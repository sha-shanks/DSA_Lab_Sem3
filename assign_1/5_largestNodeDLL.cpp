#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node* prev;
    Node* next;
};

void insertAtEnd(Node** head, int value){
    Node* newNode = new Node();
    newNode->value = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (*head == nullptr){
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

int findLargestNode(Node* head){
    int largest = head->value;
    Node* current = head->next;
    
    if (head == nullptr) {
        cout << "Empty list!" << endl;
        return 0;
    }
    
    while (current != nullptr) {
        if (current->value > largest){
            largest = current->value;
        }
        current = current->next;
    }
    
    return largest;
}

int main() {
    Node* head = nullptr;
    int noOfEle, element;

    cout << "ENter the number of elements to insert in the DLL: ";
    cin >> noOfEle;

    cout << "Enter the elements: " << endl;
    for(int i=0; i < noOfEle; i++){
        cin >> element;
        insertAtEnd(&head, element);
    }
    
    int largestNode = findLargestNode(head);
    
    if (largestNode != -1){
        cout << "The largest node in the DLL is: " << largestNode << endl;
    }
    
    return 0;
}
