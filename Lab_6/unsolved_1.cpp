#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

//can do without making a class for LL, did a class just to try how it works
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int data) {
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

    void deleteAtPosition(int position) {
        if (head == nullptr || position < 0) {
            cout << "Invalid position or empty list." << endl;
            return;
        }

        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        int count = 0;
        while (count < position - 1 && current->next != nullptr) {
            current = current->next;
            count++;
        }

        if (current->next == nullptr) {
            cout << "Position exceeds the length of the list." << endl;
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
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
    LinkedList myList;
    int numElements, deletePos;

    cout << "Enter thhe number of elements to be inserted at the end: ";
    cin >> numElements;
    
    cout << endl << "Enter the elemenets:";
    for(int i = 0; i < numElements; i++){
        int element;
        cin >> element;
        myList.insertAtEnd(element);
    }

    //myList.insertAtEnd(1);
    //myList.insertAtEnd(2);
    //myList.insertAtEnd(3);

    cout << "Original LL: ";
    myList.printLL();

    cout << "Enter the element position to be deleted at: ";
    cin >> deletePos;
    myList.deleteAtPosition(deletePos);

    cout << endl << "LL after deleting node at position " << deletePos << ": ";
    myList.printLL();

    return 0;
}
