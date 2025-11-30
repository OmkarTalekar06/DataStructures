#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* createNode(int value){
    Node* newNode = new Node;
    newNode -> data = value;
    newNode ->next = nullptr;
    return newNode; 
}

void insertAtBeggining(Node* & head, int value){
    Node* newNode = createNode(value);
    newNode -> next = head;
    head = newNode;
}

void insertAtEnd(Node* & head, int value){
    Node* newNode = createNode(value);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp-> next != nullptr)
    {
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void insertAtPosition(Node* & head, int value, int position){
    if (position == 0)
    {
        insertAtBeggining(head, value);
        return;
    }
    
    Node* newNode = createNode(value);
    Node* temp = head;
    for (int i = 0; i < position - 1 && temp != nullptr; i++)
    {
        temp = temp -> next;
    }
    
    if (temp == nullptr)
    {
        cout<<"Position out of range!";
        delete newNode;
        return;
    }
    
    newNode ->next = temp ->next;
    temp -> next = newNode;
}

void displayList(Node* head){
    cout<<"Linked List : ";
    while (head != nullptr)
    {
        cout<<head -> data << "->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = nullptr;

    insertAtEnd(head, 100);
    insertAtEnd(head, 200);
    insertAtEnd(head, 300);

    cout<<"Initial list : \n";
    displayList(head);

    insertAtBeggining(head, 50);
    cout<<"\nAfter inserting 50 at the beggining : \n";
    displayList(head);

    insertAtEnd(head, 400);
    cout<<"\nAfter inserting 400 at the end : \n";
    displayList(head);

    insertAtPosition(head, 250,3);
    cout<<"\nAfter inserting 250 at the 3rd pos : \n";
    displayList(head);

    return 0;
}