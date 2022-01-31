#include <iostream>
using namespace std;
class queue{
    int* arr;
    int f;
    int b;
    int size;
    public:
    queue(int n){
        arr= new int[n];
        f=-1;
        b=-1;
        size=n;
    }
    void push(int x){
        if(b==size-1){
            cout<<"Queue is full"<<endl;
            return;
        }
        b++;
        arr[b]=x;
        cout<<"Inserted Element "<<x<<endl;
        if(f=-1){
            f++;
        }
    }
    void pop(){
        if(f==-1 || f>b){
            cout<<"No element in Queue"<<endl;
            return;
        }
        cout<<"Removed element "<<arr[f]<<endl;
        f++;
    }
};
int main(){
    queue s=queue(5);
    s.push(1);//inserting 1
    s.push(2);//inserting 2
    s.push(3);//inserting 3
    s.push(4);//inserting 4
    s.push(5);//inserting 5
    s.push(6);//inserting 6
    //since the queue is full it will return "Queue is full"
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    //since the queue is now empty it will return "Queue is empty"
}