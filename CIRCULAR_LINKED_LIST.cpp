#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }



    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    bool search(int value) {
        if (!head) {
            return false;
        }

        Node* temp = head;
        do {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        } while (temp != head);

        return false;
    }

    void remove(int value) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        do {
            if (current->data == value) {
                if (prev) {
                    prev->next = current->next;
                    if (current == head) {
                        head = current->next;
                    }
                    delete current;
                    return;
                } else {
                    // Removing the head node
                    Node* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    if (head == head->next) {
                        delete head;
                        head = nullptr;
                        return;
                    }
                    last->next = head->next;
                    delete head;
                    head = last->next;
                    return;
                }
            }
            prev = current;
            current = current->next;
        } while (current != head);

        cout << "Element not found." << endl;
    }

    void concatenate(CircularLinkedList& list) {
        if (!list.head) {
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = list.head;
        temp = list.head;
        while (temp->next != list.head) {
            temp = temp->next;
        }

        temp->next = head;
    }
};

int main() {
    CircularLinkedList list1, list2;

    // Insertion
    list1.insert(1);
    list1.insert(2);
    list1.insert(3);

    list2.insert(4);
    list2.insert(5);

    // Display
    cout << "List 1: ";
    list1.display();

    cout << "List 2: ";
    list2.display();

    // Search
    cout << "Search 3 in List 1: " << (list1.search(3) ? "Found" : "Not Found") << endl;

    // Deletion
    list1.remove(2);

    // Display after deletion
    cout << "List 1 after deletion: ";
    list1.display();

    // Concatenate
    list1.concatenate(list2);

    // Display after concatenation
    cout << "List 1 after concatenation with List 2: ";
    list1.display();

    return 0;
}
