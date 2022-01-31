/*You have been given a singly linked list of integers where the elements are sorted in ascending order. 
Write a function that removes the consecutive duplicate values such that the given list only contains 
unique elements and returns the head to the updated list.*/
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

Node *removeDuplicates(Node *head)
{
    //Write your code here
    Node *ptr = head,*temp=NULL,*tmp=NULL;
    
    while(ptr!=NULL && ptr->next!=NULL)
    {
        temp = ptr->next;
        ptr->next=NULL;
        
        while(temp!=NULL && ptr->data == temp->data)
        {
            tmp=temp;
            temp=temp->next;
            tmp->next=NULL;
            delete(tmp);
        }
        ptr->next = temp;
        ptr = temp;
    }
    
    return head;
}