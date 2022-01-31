/*You have been given a singly linked list of integers. 
Write a function that returns the index/position of integer data denoted by 'N' (if it exists). 
Return -1 otherwise.*/
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

int findNode(Node *head, int n){
    // Write your code here.
    int i=0;
    while(head!=NULL){
        if(head->data==n){
            return i;
        }
        head=head->next;
        i++;
    }return -1;
}