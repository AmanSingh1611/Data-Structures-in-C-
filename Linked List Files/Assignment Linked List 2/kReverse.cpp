/*Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
'k' is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of 'k,'then left-out nodes, in the end, should be reversed as well.*/
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
Node *reverse_linked_list(Node *head) {
    if(head==NULL||head->next==NULL)
        return head;
    Node *smallhead=reverse_linked_list(head->next);
    head->next->next=head;
    head->next=NULL;
    return smallhead;
}
Node *kReverse(Node *head, int k)
{
	//Write your code here
    if(k==1 or k==0)
        return head;
    int i=1;
    Node*temp=head,*head1=head,*head2=head;
    while(temp!=NULL) {
        if(i%k==0||temp->next==NULL) { 
            Node*head3=temp->next;
            temp->next=NULL;
            Node*h=head2; 
            head2=reverse_linked_list(head2);
            if(head1==head){
                head1=head2;
                head=head2;
            }
            else 
                head1->next=head2;
            h->next=head3;
            head1=h;
            head2=head3;
            temp=head3;
        } 
        else{
            temp=temp->next;
        }
        i++;
    }
    return head;
}