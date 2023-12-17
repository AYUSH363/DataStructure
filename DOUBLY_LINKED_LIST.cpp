#include<iostream>
using namespace std;

class Node {
    public:
    int info;
    Node *next,*pre;

};
Node *start,*last;
void Insert();
void Delete();
void Display();

int main () {
    start = last =NULL;
    int ch;
    do {
        cout<<"1-insert"<<endl;
        cout<<"2-delete"<<endl;
        cout<<"3-display"<<endl;
        cout<<"4-exit"<<endl;
        cin>>ch;

        switch(ch) {
            case 1: Insert();
            break;
            case 2 :Delete();
            break;
            case 3 :Display();
            break;
        }
        
    }
    while(ch!=4);
}

void Insert() {
    Node *n = new Node;
    cout << "Enter info: ";
    cin >> n->info;
    n->next = NULL;
    n->pre = NULL;

    if (start == NULL) {
        start = last = n;
        return;
    }

    Node *p = NULL, *c = start;
    while (c != NULL && c->info < n->info) {
        p = c;
        c = c->next;
    }

    if (p == NULL) {
        // Insert at the beginning
        n->next = start;
        start->pre = n;
        start = n;
    } else if (c == NULL) {
        // Insert at the end
        last->next = n;
        n->pre = last;
        last = n;
    } else {
        // Insert in the middle
        p->next = n;
        n->pre = p;
        n->next = c;
        c->pre = n;
    }
}


void Delete() {
    if (start == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    int m;
    cout << "Enter info to be deleted: ";
    cin >> m;

    Node *c = start;
    while (c != NULL) {
        if (c->info == m) {
            break;
        }
        c = c->next;
    }

    if (c == NULL) {
        cout << "Invalid info. Element not found." << endl;
        return;
    }

    if (c == start && start == last) {
        start = last = NULL;
    } else if (c == start) {
        start = start->next;
        start->pre = NULL;
    } else if (c == last) {
        last = last->pre;
        last->next = NULL;
    } else {
        c->next->pre = c->pre;
        c->pre->next = c->next;
    }

    delete c;
    cout << "Element deleted successfully." << endl;
}


void Display() {
    if (start == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = start;
    cout << "List: ";
    while (current != NULL) {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;
}
