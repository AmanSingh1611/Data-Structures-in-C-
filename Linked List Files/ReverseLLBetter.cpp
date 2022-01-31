Node* reverseLL_3(Node *head) {
	if(head == NULL || head -> next == NULL) {
		return head;
	}

	Node *smallAns = reverseLL_3(head -> next);

	Node *tail = head -> next;
	tail -> next = head;
	head -> next = NULL;
	return smallAns;
}