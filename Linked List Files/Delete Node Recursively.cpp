Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
    if(head==NULL){
        return head;
    }if(pos==0){
        return head->next;
    }else{
        Node *k=deleteNodeRec(head->next,pos-1);
        head->next=k;
    }
}