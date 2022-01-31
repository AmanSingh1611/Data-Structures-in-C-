/************************************************************
 
    Following is the structure of the node class 
 
    class Node {
    	public :
    	int data;
    	Node *next;

    	Node(int data) {
        	this->data = data;
        	next = NULL;
    	}
	};

**************************************************************/


class Stack {
	// Define the data members
    int size=0;
    Node *head;
    public:
    Stack() {
        // Implement the Constructor
        head=NULL;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return size==0;
    }

    void push(int element) {
        // Implement the push() function
        Node *newNode=new Node(element);
        if(head==NULL){
            head=newNode;
            newNode->next=NULL;
            size++;
        }else{
            
            newNode->next=head;
            head=newNode;
            newNode->data=element;
            size++;
        }
    }

    int pop() {
        // Implement the pop() function
        if(size==0){
            return -1;
        }else{
            int ans=head->data;
            Node *temp=head->next;
            delete head;
            head=temp;
            size--;
            return ans;
        }
    }

    int top() {
        // Implement the top() function
        if(size==0){
            return -1;
        }else{
            return head->data;
        }
    }
};