#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x){
        data = x;
        next = prev = NULL;
    }
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque(){
        front = rear = NULL;
    }

    void insertFront(int x) {
        Node* newNode = new Node(x);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    int deleteRear() {
        if (isEmpty()) {
            cout << "Deque UNDERFLOW!" << endl;
            return -1;
        }

        int deletedData = rear->data;

        if (front == rear) {
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = rear->prev;
            delete rear;
            rear = temp;
            rear->next = nullptr;
        }

        return deletedData;
    }

    bool isEmpty() {
        return front == nullptr && rear == nullptr;
    }

    void display() {
        Node* current = front;
        cout << "Deque elements: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Deque d;
    int choice, value;

    while (1) {
        cout << "Menu:" << endl;
        cout << "1. Insert at Front" << endl;
        cout << "2. Delete at Rear" << endl;
        cout << "3. Display Deque" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to be inserted: ";
                cin >> value;
                d.insertFront(value);
                break;
            case 2:
                value = d.deleteRear();
                if (value != -1) {
                    cout << "Deleted element: " << value << endl;
                }
                break;
            case 3:
                d.display();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
        cout << endl;
    }

    return 0;
}