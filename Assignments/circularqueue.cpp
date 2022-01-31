#include <iostream>
using namespace std;
class circularQueue{
    int f;
    int b;
    int size;
    int* arr;
    public:
    circularQueue(int n){
        f=-1;
        b=-1;
        arr=new int[n];
        size=n;
    }
    bool full(){
        if(f == 0 && b == size - 1){
            return true;
        }
        if(f == b + 1) {
            return true;
        }
        return false;
    }
    bool empty(){
        return f==-1;
    }
    void push(int x){
        if(full()){
            cout<<"Circular Queue is full"<<endl;
            return;
        }else{
            if(f==-1){
                f=0;
            }
            b=(b+1)%size;
            arr[b]=x;
            cout<<"Inserted Element "<<x<<endl;
        }
    }void pop(){
        if(empty()){
            cout<<"Circular Queue is empty"<<endl;
            return;
        }else{
            cout<<"Removed Element "<<arr[f]<<endl;
            if(b==f){
                b=-1;
                f=-1;
                //only one element was present therefore "f" & "b" are reinitialised.
            }
            else{
                f=(f+1)%size;
            }
        }
    }
};
int main(){
    circularQueue s=circularQueue(5);
    s.push(1);//inseriing 1
    s.push(2);//inseriing 2
    s.push(3);//inseriing 3
    s.push(4);//inseriing 4
    s.push(5);//inseriing 5
    s.push(6);//inseriing 6
    //since the queue is full it will return "Circular Queue is full"
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    //since the queue is now empty it will return "Circular Queue is empty"
}