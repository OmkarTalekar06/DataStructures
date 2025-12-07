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

void preorder(Node* root){
    if (root == nullptr)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    Node* root = nullptr;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout<<"Pre- order Traver : ";
    preorder(root);

    return 0;
}