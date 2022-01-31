#include <iostream>
using namespace std;
class Node {
	public :
	int data;
	Node *next;

	Node(int data) {
		this -> data = data;
		next = NULL;
	}
};
int length(Node* head){
    if(head==NULL){
        return 0;
    }return 1+length(head->next);
}
Node* insert(Node *head, int i, int data) {
	Node *newNode = new Node(data);
	int count = 0;
	Node *temp = head;
	if(i == 0) {
		newNode -> next = head;
		head = newNode;
		return head;
	}

	while(temp != NULL && count < i - 1) {
		temp = temp -> next;
		count++;
	}
	if(temp != NULL) {
		Node *a = temp -> next;
		temp -> next = newNode;
		newNode -> next = a;
	}
	return head;
}
void print(Node *head) {
	while(head != NULL) {
		cout << head -> data << "->";
		head = head -> next;
	}cout<<"NULL"<<endl;
}
Node *delete_(Node *head, int pos) {
    if(head==NULL){
        return head;
    }if(pos==0){
        return head->next;
    }else{
        Node *k=delete_(head->next,pos-1);
        head->next=k;
    }
}
int main(){
    Node* n1=new Node(10);//creating node having data 10
    Node* n2=new Node(20);//creating node having data 20
    Node* n3=new Node(30);//creating node having data 30
    Node* n4=new Node(40);//creating node having data 40
    Node* n5=new Node(50);//creating node having data 50
    Node* head=n1;
    head->next=n2;//linking nodes
    n2->next=n3;//linking nodes
    n3->next=n4;//linking nodes
    n4->next=n5;//linking nodes
    n5->next=NULL;//linking nodes
    cout<<length(head)<<endl;
    print(head);
    insert(head,3,100);//inserting data 100 at 3rd position in previous linked list
    cout<<length(head)<<endl;
    print(head);
    delete_(head,4);//deleting node at 4th position
    cout<<length(head)<<endl;
    print(head);
}