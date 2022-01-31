Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    if(head1==NULL){
        return head2;
    }else if(head2==NULL){
        return head1;
    }
    Node *fh=NULL;
    Node *ft=NULL;
    if(head1->data>=head2->data){
        fh=head2;
        ft=head2;
        head2=head2->next;
    }else{
        fh=head1;
        ft=head1;
        head1=head1->next;
    }
    while(head1!=NULL && head2!=NULL){
        if(head1->data>=head2->data){
            ft->next=head2;
            ft=head2;
        	head2=head2->next;
        }else{
            ft->next=head1;
            ft=head1;
            head1=head1->next;
        }
    }if(head1!=NULL){
        ft->next=head1;
    }else{
        ft->next=head2;
    }return fh;
}
Node *midPoint(Node *head)
{
    // Write your code here
    while(head!=NULL && head->next!=NULL){ 
        Node *fast=head->next;
        Node *slow=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }return slow;
    }return head;
}

Node *mergeSort(Node *head)
{
	//Write your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *mid=midPoint(head);
    Node *left=head;
    Node *right=mid->next;
    mid->next=NULL;
    left=mergeSort(left);
    right=mergeSort(right);
    Node *f=mergeTwoSortedLinkedLists(left,right);
    return f;
}