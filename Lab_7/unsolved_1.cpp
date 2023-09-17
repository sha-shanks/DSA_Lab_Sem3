#include <iostream>
using namespace std;

//Calculate the size ot the tree

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = right = nullptr;
    }
};

int nodeCounter(Node* head){
    if(!head){
        return 0;
    }
    return (1+nodeCounter(head->left)+nodeCounter(head->right));
    
}

/*
Node Structure
        5
      /   \
    35     3
    / \   / \
   91 1  45  NULL
*/

int main(){
    Node* root = new Node(5);
    root->left = new Node(35);
    root->right = new Node(3);
    root->left->left = new Node(91);
    root->left->right = new Node(1);
    root->right->left = new Node(45);

    cout << "The total number of nodes in the given binary tree is: " << nodeCounter(root);

    return 0;
}