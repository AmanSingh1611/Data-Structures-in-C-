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