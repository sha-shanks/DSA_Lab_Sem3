#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLL {
private:
    Node* head;
public:
    DoublyLL() {
        head = nullptr;
    }

    // Fn to insert a node at the end
    void insertAtEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    // Fn to delete even nodes
    void deleteEvenNodes() {
        Node* current = head;

        while (current != nullptr) {
            if (current->data % 2 == 0) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                if (current == head) {
                    head = current->next;
                }
                Node* temp = current;
                current = current->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }

    void printLL() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
}
};

int main() {
    DoublyLL myList;

    // Insert nodes at the end or use for loop to get user defined values
    myList.insertAtEnd(1);
    myList.insertAtEnd(2);
    myList.insertAtEnd(3);
    myList.insertAtEnd(4);
    myList.insertAtEnd(5);
    myList.insertAtEnd(6);
    myList.insertAtEnd(7);
    myList.insertAtEnd(8);

    cout << "Original Doubly LL: ";
    myList.printLL();

    // Delete even nodes
    myList.deleteEvenNodes();

    cout << "Doubly LL after Deleting Even Nodes: ";
    myList.printLL();

    return 0;
}
