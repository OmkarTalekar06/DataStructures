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
    newNode -> next = nullptr;
    return newNode;
}

void insertAtEnd(Node* & head, int value){
    Node* newNode = createNode(value);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp -> next != nullptr)
    {
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void deleteAtposition(Node* & head, int position){
    if (head == nullptr)
    {
        cout<<"List is empty.!\n";
        return;
    }
    Node* temp = head;

    if (position == 1)
    {
        head = head -> next;
        delete temp;
        return;
    }
    
    for (int i = 1; i < position-1 && temp != nullptr; i++)
    {
        temp = temp -> next;
    }
    
    if (temp == nullptr || temp-> next == nullptr)
    {
        cout<<"Position out of range";
        return;
    }
    
    Node* nodetodelete = temp -> next;
    temp -> next = nodetodelete -> next;
    delete nodetodelete;
    
} 

void displayList(Node* head){
    cout<<"Linked list : ";
    while (head != nullptr)
    {
        cout << head -> data << " -> ";
        head = head -> next;
    }
    cout<<"NULL"<<endl;
    
}

int main(){
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);

    cout<<"Orignal list : ";
    displayList(head);

    int pos;
    cout<<"Enter the position to delete : "<<endl;
    cin>>pos;

    deleteAtposition(head, pos);

    cout<<"\nList after the deleting : ";
    displayList(head);

    return 0;

}