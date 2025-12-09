#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value){
    Node* newNode = new Node();
    newNode ->data = value;
    newNode -> left = newNode ->right = NULL;
    return newNode;
}

void inorderTraversal(Node* root){
    if (root==NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main(){

    Node* root = createNode(1);
    root ->left = createNode(2);
    root ->right= createNode(3);
    root ->left ->left = createNode(4);
    root ->left ->right = createNode(5);

    cout<<"Inorder Traversal : ";
    inorderTraversal(root);
    return 0;
}