#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        next=NULL;
    }
};
int length(node* head){
    node* temp=head;
    int count=0;
    do{
        count++;
        temp=temp->next;
    }while(temp!=head);
    return count;
}
void insert(node* &head,int val){
    node* newNode=new node(val);
    cout<<"Inserted Data is "<<val<<endl;
    if(head==NULL){
        node* temp=head;
        newNode->next=newNode;
        head=newNode;
        return;
    }else{
        node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }temp->next=newNode;
        newNode->next=head;
        return;
    }
}
void print(node* head){
    node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}
void delete_(node* &head,int pos){
    node* temp=head;
    if(pos==1){
        while(temp->next!=head){
            temp=temp->next;
        }node* todelete=head;
        cout<<"Deleted Data "<<head->data<<endl;
        temp->next=head->next;
        head=head->next;
        delete todelete;
        return;
    }
    int count=1;
    while(count!=pos-1){
        temp=temp->next;
        count++;
    }node* todelete=temp->next;
    cout<<"Deleted Data "<<temp->next->data<<endl;
    temp->next=temp->next->next;
    delete todelete;
}
int main(){
    node* head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    cout<<"Length Of List After Insertion "<<length(head)<<endl;
    print(head);
    delete_(head,1);// Important!!! 1 based indexing
    delete_(head,3);// Important!!! 1 based indexing
    cout<<"Length Of List After Deletion  "<<length(head)<<endl;
    print(head);
}