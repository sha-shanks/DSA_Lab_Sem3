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

Node* newNode(int data){
    Node* temp = new Node(data);
    temp->left = temp->right = NULL;
    return temp;
}

Node* insertNode(Node* node, int data){
    if(!node)
        return newNode(data);
    
    if(data < node->key){
        node->left = insertNode(node->left,data);
    }else{
        node->right = insertNode(node->right,data);
    }
}

int minEle(Node* root){
    if(!root->left){
        return root->key;
    }
    else{
        return minEle(root->left);
    }
}

int main(){
    Node* root = NULL;
    int numEle, ele;
    cout << "Enter the number of nodes: ";
    cin >> numEle;

    cout << "Enter the node keys: ";
    for(int i = 0; i < numEle; i++){
        cin >> ele;
        root = insertNode(root,ele);
    }

    cout << "The element with the minimum value is " << minEle(root);
    return 0;

    return 0;
}