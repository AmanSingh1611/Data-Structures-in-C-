#include <iostream>
using namespace std;
#include "Node.cpp"
int length(Node *head){
    int i=0;
    while(head!=NULL){
        i++;
        head=head->next;
    }return i;
}
Node *bubbleSort(Node *head){
    int len=length(head);
    for(int i=0;i<len;i++){
        Node *prev=NULL ,*curr=head ,*frd=head->next;
        while(curr->next!=NULL){
            if(curr->data>frd->data){
                if(prev!=NULL){
                    prev->next=frd;
                    curr->next=frd->next;
                    frd->next=curr;
                    prev=frd;
                    frd=curr->next;
                }else{
                    head=frd;
                    curr->next=frd->next;
                    frd->next=curr;
                    prev=frd;
                    frd=curr->next;
                }
            }else{
                prev=curr;
                curr=frd;
                frd=frd->next;
            }   
        }    
    }
    return head;
}