#include <iostream>
using namespace std;

class Node{
public:
    int key;
    Node* left;
    Node* right;

    Node(int value){
        key = value;
        left = right = nullptr;
    }
};

bool areIdentical(Node* r1, Node* r2){
    if(!r1 && !r2){
        return true;
    }else{
        return (r1->key==r2->key) && areIdentical(r1->left,r2->left) && areIdentical(r1->right,r2->right);
    }
}

int main(){
    Node* root1 = new Node(0);
    Node* root2 = new Node(0);
    //Give larger trees of your choice

    if(areIdentical(root1,root2))
        cout << "The two binary trees are identical.";
    else
        cout << "The two binary trees are not identical";

    return 0;
}