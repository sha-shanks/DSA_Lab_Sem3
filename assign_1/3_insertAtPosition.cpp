#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node* next;
};

void insertAtPosition(Node* head, int newValue, int position=6){
    if(position < 0){
        cout << "Invalid position!" << endl;
        return;
    }
    
    Node* newNode = new Node();
    newNode->value = newValue;
    newNode->next = nullptr;
    
    Node* current = head;
    for(int i = 0; i < position - 1; i++){
        if (current->next == nullptr)
            break;
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
}

void printLL(Node* head){
    Node* current = head;
    while(current != nullptr){
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

int main(){
    int element, noOfEle = 15;
    Node* head = new Node();
    head->value = 1;
    head->next = nullptr;
    
    for(int i = 2; i <= noOfEle; i++){
        Node* newNode = new Node();
        newNode->value = i*3;
        newNode->next = nullptr;
        
        Node* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        
        current->next = newNode;
    }

    cout << "Before insertion: ";
    printLL(head);
    
    cout << "Enter the element to be inserted at position 6: ";
    cin >> element;
    insertAtPosition(head, element);
    
    cout << "After insertion of element at position 6: ";
    printLL(head);

    return 0;
}
