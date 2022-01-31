/*You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' 
Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. 
Continue the same until the end of the linked list.
To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.*/
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here\
    // edge case  not a base case
    if(N==0){
        return head;
    }
    if(M==0){
        return NULL;
    }
    //base case
    if(head==NULL || head->next==NULL) 
    {
        return head;
    }
    
    Node *temp=head;
    int count1=0;
    int count2=0;
    while(temp->next !=NULL && count1<M-1) //travel M nodes
    {   count1++;
        temp=temp->next;
        
    }
    Node *t1=temp;
   // t1=temp;
    temp=temp->next;
    if(temp==NULL)
        return head;
    
    while(temp->next!=NULL && count2<N-1)
    {   count2++;
        temp=temp->next;
      
    }
    
    Node *t2;
    t2=temp->next;
      

    Node *m=skipMdeleteN(t2,M,N);   
    t1->next=m;
    return head;
}