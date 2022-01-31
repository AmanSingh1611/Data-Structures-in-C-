#include <iostream>
using namespace std;
class Deque { 
    int arr[10];
    int front;
    int rear;
    int size;
    public :
    Deque(int size) {
        front = -1;
        rear = 0;
        this -> size = size;
    }
    //Checks whether deque is full or not.
    bool isFull() {
        // used % operator is insertion and deletion is in circular manner 
        return (front == (rear + 1) % size);
    }
    //Checks whether Deque is empty or not.
    bool isEmpty () {
        return (front == -1);
    }
    // Inserts an element at front 
    void push_front(int input) {
        if (isFull()) {
            cout << "Dequeue is Full"<<endl;
            return;
        }
        cout<<"Pushed Element "<<input<<" to front"<<endl;
        if (isEmpty()) {    //isEmpty() ?
            front = 0;
            rear = 0;
        }
        else {
            // used % operator is insertion is in circular manner
            front = ((front - 1) % size + size) % size;
        }
        arr[front] = input ;
    } 
    // function to inset element at rear end of Deque. 
    void push_rear(int input) {
        if (isFull()) { 
            cout << "Dequeue is Full"<<endl;
            return;
        }
        cout<<"Pushed Element "<<input<<" at Rear"<<endl;
        if (isEmpty()) { 
            front = 0;
            rear = 0;
        }
        else {
            // used % operator is insertion is in circular manner
            rear = (rear + 1) % size;
        }
        arr[rear] = input;
    }
    // Deletes element at front end of Deque
    void pop_front() {
        if (isEmpty()) {
            cout << "Dequeue is Empty";
            return ;
        }
        cout<<"Poped Element is "<<getFront()<<endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            // used % operator is deletion is in circular manner
            front = (front + 1) % size;
        }
    }
    // Delete element at rear end of Deque
    void pop_rear() { 
        if (isEmpty()) {
            cout << "Dequeue is Empty";
            return ;
        }
        cout<<"Poped Element is "<<getRear()<<endl;
        if (front == rear) { 
            front = -1;
            rear = -1; 
        }
        else {
            // used % operator is deletion is in circular manner
            rear = ((rear-1) % size + size) % size;
        }
    }
    // Returns front element of Deque 
    int getFront() {
        if (isEmpty()) { 
            return -1 ;
        }
        return arr[front];
    }
    // function return rear element of Deque 
    int getRear() {
        if(isEmpty()) {
            return -1 ;
        }
        return arr[rear];
    }
};
int main(){
    Deque x(5);
    x.getRear();
    x.getFront();
    x.push_front(10);//Adding Element to front
    x.push_front(20);//Adding Element to front
    x.push_front(30);//Adding Element to front
    x.push_rear(40); //Adding Element to rear
    x.push_rear(50); //Adding Element to rear
    x.push_rear(60); //Adding Element to rear
    cout<<x.getFront()<<endl;
    x.pop_front();   //Deleting element from front
    cout<<x.getRear()<<endl;
    x.pop_rear();   //Deleting element from rear
}