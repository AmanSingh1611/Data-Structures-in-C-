/*You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' 
Swap the nodes that are present at the 'i-th' and 'j-th' positions.*/
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

Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
    if(i==j){
        return head;
    }
    Node *temp = head;
    Node *pre = NULL;
    Node *p1 = NULL;
    Node *p2 = NULL;
    Node *c1 = head;
    Node *c2 = head;
    int x=0;
    while(temp != NULL){
        if(x == i){
            p1 = pre;
            c1 = temp;
        }
        else if(x == j){
            p2 = pre;
            c2 = temp;
        }
        pre = temp;
        temp = temp->next;
        x++;
    }
    if(p1 != NULL)
        p1->next = c2;
    else
        head = c2;
    if(p2 != NULL)
        p2->next = c1;
    else
        head = c1;
    Node *TEMP = c2->next;
    c2->next = c1->next;
    c1->next = TEMP;
    return head;
}