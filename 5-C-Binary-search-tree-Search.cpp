#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int value){
    if (root == nullptr)
    {
        return createNode(value);
    }
    if (value<root->data)
    {
        root->left = insert(root->left,value);
    }else if (value>root->data)
    {
        root->right = insert(root->right,value);
    }
    return root;
}

void inorder(Node* root){
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    
}

Node* search(Node* root, int key){
    if (root==nullptr || root->data == key)
    {
        return root;
    }
    if (key<root->data)
    {
        return search(root->left,key);
    }
    return search(root->right, key);
    
}

int main(){
    Node* root = NULL;
    int value,choice;
    int key;
    do
    {
        cout<<"1.Inserting value\n2.Printing BST\n3.Search inBST\n4.Exit"<<endl;
        cout<<"Enter a choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter the value to insert : ";
            cin>>value;
            root=insert(root, value);
            cout<<value<<" insserted";
            break;
        case 2:
            cout<<"Binary Tree : ";
            inorder(root);
            cout<<"\n";
            break;
        case 3:
            cout<<"Enter value to search : ";
            cin>>key;
            if (search(root, key))
            {
                cout<<"Node "<<key<<" found in BST"<<endl;
            }else{
                cout<<"Node "<<key<<" not found in BST"<<endl;
            }
            break;
            
        case 4:
            cout<<"Exiting...";
            break;

        default:
            cout<<"Invalid choice";
            break;
        }
    } while (choice<5);
    
}