#include<iostream>
using namespace std;

class node {
public:
    int info;
    node* left, *right;
};

node* root;

void Insert();
void Preorder(node*);
void Inorder(node*);
void Postorder(node*);
void Delete(int);
void disp();
void delone(node*, node*);
void delleaf(node*, node*);
void deltwo(node*, node*);

int main() {
    int ch;
    root = NULL;

    do {
        cout << "Press 1 for insert" << endl;
        cout << "Press 2 for Preorder" << endl;
        cout << "Press 3 for Inorder" << endl;
        cout << "Press 4 for Postorder" << endl;
        cout << "Press 5 for Delete" << endl;
        cout << "Press 6 for display" << endl;
        cout << "Press 7 for exit" << endl;

        cin >> ch;

        switch (ch) {
        case 1: Insert();
            break;
        case 2: Preorder(root);
            cout << endl;
            break;
        case 3: Inorder(root);
            cout << endl;
            break;
        case 4: Postorder(root);
            cout << endl;
            break;
        case 5: 
            int m;
            cout << "Enter info to delete: ";
            cin >> m;
            Delete(m);
            break;
        case 6: disp();
            break;
        case 7: exit(0);
            break;
        }

    } while (ch != 7);

    return 0;
}

void Insert() {
    node* n = new node; // dynamic allocation
    cout << "enter info: ";
    cin >> n->info;
    n->left = NULL;
    n->right = NULL;

    if (root == NULL) {
        root = n;
        return;
    }

    node* parent, *current;
    current = root;

    while (current != NULL) {
        parent = current;
        if (n->info > current->info) {
            current = current->right;
        } else {
            current = current->left;
        }
    }

    if (n->info > parent->info) {
        parent->right = n;
    } else {
        parent->left = n;
    }
}

void Preorder(node* ptr) {
    if (ptr == NULL)
        return;
    cout << ptr->info << " ";
    Preorder(ptr->left);
    Preorder(ptr->right);
}

void Inorder(node* ptr) {
    if (ptr == NULL)
        return;

    Inorder(ptr->left);
    cout << ptr->info << " ";
    Inorder(ptr->right);
}

void Postorder(node* ptr) {
    if (ptr == NULL)
        return;

    Postorder(ptr->left);
    Postorder(ptr->right);
    cout << ptr->info << " ";
}

void delleaf(node* p, node* c) {
    if (c == p->right) {
        p->right = NULL;
    } else {
        p->left = NULL;
    }
    delete c;
}

void delone(node* p, node* c) {
    node* cc;
    if (c->left != NULL) {
        cc = c->left;
    } else {
        cc = c->right;
    }
    if (c == p->left) {
        p->left = cc;
    } else {
        p->right = cc;
    }
    delete c;
}

void deltwo(node* parent, node* current) {
    node* s_p, *s;
    s = current->right;

    while (s->left != NULL) {
        s_p = s;
        s = s->left;
    }

    current->info = s->info;
    if (s->left == NULL && s->right == NULL) {
        delleaf(s_p, s);
    } else {
        delone(s_p, s);
    }
}

void Delete(int m) {
    node* parent = NULL, *current = root;
    while (current != NULL) {
        if (m > current->info) {
            parent = current;
            current = current->right;
        } else if (m < current->info) {
            parent = current;
            current = current->left;
        } else {
            break;
        }
    }

    if (current == NULL) {
        cout << "INVALID INFO" << endl;
        return;
    }

    // Handle different deletion scenarios
    if (current->left == NULL && current->right == NULL) { // Leaf node
        if (parent != NULL) {
            if (parent->left == current) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        }
        delete current;
    } else if (current->left == NULL || current->right == NULL) { // Single child node
        node* child = current->left ? current->left : current->right;
        if (parent != NULL) {
            if (parent->left == current) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        } else {
            root = child;
        }
        delete current;
    } else { // Two child node
        node* successor = current->right;
        node* s_parent = current;
        while (successor->left != NULL) {
            s_parent = successor;
            successor = successor->left;
        }

        current->info = successor->info;
        if (successor == current->right) {
            current->right = successor->right;
        } else {
            s_parent->left = successor->right;
        }
        delete successor;
    }
}

void disp() {
    cout << "BST in Preorder: ";
    Preorder(root);
    cout << endl;

    cout << "BST in Inorder: ";
    Inorder(root);
    cout << endl;

    cout << "BST in Postorder: ";
    Postorder(root);
    cout << endl;
}
