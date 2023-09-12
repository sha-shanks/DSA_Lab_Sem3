#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

int countNodes(Node* head) {
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printLL(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);

    //Our use the for loop to insert user defined elements :)
    
    cout << "Original LL: ";
    printLL(head);

    int nodeCount = countNodes(head);

    cout << "Number of nodes in the LL: " << nodeCount << endl;

    return 0;
}
