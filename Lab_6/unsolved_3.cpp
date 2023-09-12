#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

//didnt use a recursive fn
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void deletePrimes(Node*& head) {
    if (head == nullptr) {
        return; // exiting the fn without returning anything 
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (isPrime(current->data)) {
            // if the Node has a prime number, delete it
            if (prev == nullptr) {
                // The prime number is in the head node, tbh not required
                head = current->next;
                delete current;
                current = head;
            } else {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
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

    // could also insert user defined nodes instead
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);
    insertAtEnd(head, 7);
    insertAtEnd(head, 8);

    //original LL
    cout << "Original LL: ";
    printLL(head);

    // Delete prime 
    deletePrimes(head);

    //Modified liust
    cout << "LL after Deleting Prime Numbers: ";
    printLL(head);

    return 0;
}