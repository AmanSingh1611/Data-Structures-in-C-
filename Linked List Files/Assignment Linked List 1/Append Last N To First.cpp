/*You have been given a singly linked list of integers along with an integer 'N'.
Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.*/
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
int length(Node *head) {
    // Write your code here
    if(head==NULL){
        return 0;
    }else{
        return 1+length(head->next);
    }
}
Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    Node *temp=head;
    Node *newHead=head;
    Node *tail=head;
    int steps=length(head)-n;
    if(steps<0){
        return head;
    }
    while(tail->next!=NULL){
        tail=tail->next;
    }
    for(int i=0;i<steps-1;i++){
        newHead=newHead->next;
    }
    tail->next=head;
    head=newHead->next;
    newHead->next=NULL;
    return head;
       
}