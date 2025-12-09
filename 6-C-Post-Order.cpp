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

void postorder(Node* root){
    if (root==nullptr)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root = nullptr;

    root = createNode(1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);

    cout<<"Post-Order Traversal : ";
    postorder(root);

    return 0;
}