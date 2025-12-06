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
    newNode ->data = value;
    newNode -> left= newNode -> right = NULL;
    return newNode;
}

Node* insert(Node* root, int value){
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root ->data)
    {
        root -> left = insert(root->left, value);
    }else if (value > root->data)
    {
        root ->right = insert(root->right, value);
    }
    return root;
}

int main(){
    Node* root = NULL;
    int value = 7;
    root = insert(root, value);
    cout<<value<<" inserted.";
}