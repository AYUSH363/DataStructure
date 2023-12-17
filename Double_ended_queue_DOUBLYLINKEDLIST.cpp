#include <iostream>

using namespace std;

// Node structure for doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Double-ended queue class
class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() : front(nullptr), rear(nullptr) {}

    // Function to add an element to the front of the deque
    void addToFront(int value) {
        Node* newNode = new Node(value);

        if (!front) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    // Function to add an element to the rear of the deque
    void addToRear(int value) {
        Node* newNode = new Node(value);

        if (!rear) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to display elements from the front of the deque
    void displayFromFront() {
        Node* current = front;
        cout << "Deque from front: ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Function to display elements from the rear of the deque
    void displayFromRear() {
        Node* current = rear;
        cout << "Deque from rear: ";
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    Deque deque;

    // Add elements to the front and rear of the deque
    deque.addToFront(30);
    deque.addToFront(20);
    deque.addToRear(40);
    deque.addToRear(50);

    // Display elements from the front and rear of the deque
    deque.displayFromFront();
    deque.displayFromRear();

    return 0;
}
