#include<iostream>
using namespace std;

class queue{
    int arr[5];
    int front, rear;
    public:

    queue(){
        front = -1;
        rear = -1;
    }
    void enqueue(int x){
        if (rear == 5-1)
        {
            cout<<"Queue is full";
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        arr[++rear] = x;
        cout<<x<<" added to queue\n";
    }
    void dequeue(){
        if (front == -1 || front > rear)
        {
            cout<<"Queue is empty!";
            return;
        }
        cout<<arr[front]<<" removed from queue \n";
        if (front == rear)
        {
            front = rear = -1;
        }else{
            front++;
        }
    }

    void display(){
        if (front == -1 || front > rear)
        {
            cout<<"Queue is empty";
            return;
        }
        cout<<"Queue : ";
        for (int i = front; i <= rear; i++)
        {
            cout<<arr[i]<<" ";
        }
         cout<<"\n";
        
    }
};

int main(){
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}