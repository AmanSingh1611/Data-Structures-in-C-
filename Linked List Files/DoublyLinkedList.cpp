#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* prev;
    node* next;
    node(int data){
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};
int length(node* head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }return count;
}
void insert(node* &head,int val){
    node* newNode=new node(val);
    cout<<"Inserted Data is "<<val<<endl;
    if(head==NULL){
        newNode->next=head;
        if(head!=NULL){
            head->prev=NULL;
        }head=newNode;
        return;
    }else{
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }temp->next=newNode;
        newNode->prev=temp;
        return;
    }
}
void delete_(node* &head,int pos){
    if(pos==0){
        node* todelete=head;
        cout<<"Deleted Data is "<<head->data<<endl;
        head=head->next;
        head->prev=NULL;
        delete todelete;
        return;
    }else{
        node* temp=head;
        int count=1;
        while( temp!=NULL && count!=pos){
            temp=temp->next;
            count++;
        }
        if(temp==NULL){
            cout<<"Index Out Of range"<<endl;
            return;
        }
        cout<<"Deleted Data is "<<temp->data<<endl;
        temp->prev->next=temp->next;
        if(temp->next!=NULL){
            temp->next->prev=temp->prev;
        }delete temp;
    }

    
}
void print(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }cout<<"NULL"<<endl;
}
int main(){
    node* head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    cout<<"Length Of List Ater Insertion "<<length(head)<<endl;
    print(head);
    delete_(head,0);// Important!!! Indexing Is 0 based
    delete_(head,3);// Important!!! Indexing Is 0 based
    cout<<"Length Of List After Deletion "<<length(head)<<endl;
    print(head);
}