#include <iostream>
using namespace std;
class stack{
    int* stacks;
    int top=-1;
    int n;
    public:
    stack(int s){
        stacks = new int[s];
        n=s;

    }
    void push(int val) {
        cout<<"The Element pushed is "<<val<<endl;
        if(top>=n-1){
        cout<<"Stack Overflow"<<endl;
        }
        else {
            top++;
            stacks[top]=val;
        }
    }
    void pop() {
        if(top<=-1){
        cout<<"Stack Underflow"<<endl;
        }
        else {
            cout<<"The popped element is "<< stacks[top] <<endl;
            top--;
        }
    }
};
int main(){
    stack s=stack(5);
    s.push(1);//inserted element in stack
    s.push(2);//inserted element in stack
    s.push(3);//inserted element in stack
    s.push(4);//inserted element in stack
    s.push(5);//inserted element in stack
    s.push(6);//inserted element in stack
    //since stack size is full it will return over flow
    s.pop();//removed element from stack
    s.pop();//removed element from stack
    s.pop();//removed element from stack
    s.pop();//removed element from stack
    s.pop();//removed element from stack
    s.pop();//removed element from stack
    //stack is now empty
    //from output we can see that elements inserted first are removed first 
}