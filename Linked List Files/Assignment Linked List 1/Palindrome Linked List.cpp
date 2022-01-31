/*You have been given a head to a singly linked list of integers. 
Write a function check to whether the list given is a 'Palindrome' or not.*/
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
int length(Node *head){
    int i=0;
    while(head!=NULL){
        head=head->next;
        i++;
    }return i;
}
bool isPalindrome(Node *head)
{
    //Write your code here
    int len=length(head);
    int arr[len];
    Node *temp=head;
    if(len==0 || len==1){
        return true;
    }
    for(int i=len-1;i>=0;i--){
        arr[i]=temp->data;
        temp=temp->next;
    }
    int i=0;
    while(head!=NULL){
        if(head->data!=arr[i]){
            return false;
        }else{
            i++;
            head=head->next;
        }
    }return true;
}