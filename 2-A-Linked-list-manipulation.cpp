#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* createNode(int value){
    Node* newNode = new Node;
    newNode -> data = value;
    newNode -> next = nullptr;
    return newNode;
}

int main(){
    Node* head = nullptr;
    Node* temp = nullptr;
    Node* tail = nullptr;
    int n, value;

    cout<<"Enter number of nodes : ";
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cout<<"Enter data for node "<<i+1<<" : ";
        cin>>value;
        temp = createNode(value);

        if (head==nullptr)
        {
            head = temp;
            tail = temp;
        }else{
            tail -> next = temp;
            tail = temp;
        }
        
    }

    cout<<"Singly linked list : ";
    temp = head;
    while (temp != nullptr)
    {
        cout<<temp ->data << "->";
        temp = temp-> next;
    }
    cout<<"NULL"<<endl;
    
    return 0;
}