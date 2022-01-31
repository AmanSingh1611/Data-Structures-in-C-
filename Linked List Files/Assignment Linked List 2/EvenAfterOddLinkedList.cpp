/*For a given singly linked list of integers, 
arrange the elements such that all the even numbers are placed after the odd numbers. 
The relative order of the odd and even terms should remain unchanged.*/
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

Node *evenAfterOdd(Node *head)
{
	//write your code here
    if(head==NULL){
        return head;
    }
    Node *oh=NULL,*ot=NULL,*eh=NULL,*et=NULL;
    while(head!=NULL){
        if((head->data)%2==0){
            if(eh==NULL){
                eh=head;
                et=head;
                head=head->next;
            }else{
                et->next=head;
                et=head;
                head=head->next;
            }
        }else{
            if(oh==NULL){
                oh=head;
                ot=head;
                head=head->next;
            }else{
                ot->next=head;
                ot=head;
                head=head->next;
            }
        }
    }if(oh==NULL){
        et->next=NULL;
        return eh;
    }else if(eh==NULL){
        return oh;
    }else{
        et->next=NULL;
        ot->next=eh;
        return oh;
    }
}