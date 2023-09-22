#include<iostream>
using namespace std;

class node {
    public:
    int info;
    node *next;
};
node *start,*last;
void insert();
void Delete();
void disp();
void search();

int main() {
    start = last = NULL;
    int ch;
    do{
        cout<<"press 1 to insert"<<endl;
        cout<<"press 2 to delete "<<endl;
        cout<<"press 3 to display"<<endl;
        cout<<"press 4 to search"<<endl;
        cout<<"press 5 to exit"<<endl;

        cin>>ch;
        switch(ch)
        {
            case 1: 
            insert();
            break;
            case 2:
            Delete();
            break;
            case 3:
            disp();
            break;
            case 4:
            search();
            break;

        }
        
    }
    while(ch!=5);


}

void insert() {
    node *n = new node;
    cout << "enter info: ";
    cin >> n->info;
    n->next = NULL;

    if (start == NULL) {
        start = last = n;
        return;
    }

    node *p = NULL, *c = start;
    
    while (c != NULL) {
        if (c->info > n->info) {
            break;
        }
        p = c;
        c = c->next;
    }

    if (c == start) {
        n->next = start;
        start = n;
    } else if (c == NULL) {
        last->next = n;
        last = n;
    } else {
        p->next = n;
        n->next = c;
    }
}


void Delete() {
    if (start == NULL) {
        cout << "No elements to delete" << endl;
        return; // Return early when there are no elements to delete
    }

    int m;
    cout << "Enter info to be deleted: ";
    cin >> m;

    node *p = NULL, *c = start;

    while (c != NULL) {
        if (c->info == m) {
            break;
        }
        p = c;
        c = c->next;
    }

    if (c == NULL) {
        cout << "Element not found in the list" << endl;
        return; // Return if the element is not found
    }

    if (c == start) {
        start = start->next;
    } else if (c == last) {
        p->next = NULL;
        last = p;
    } else {
        p->next = c->next;
    }

    delete c;
}



void disp() {
    node *c;
    c = start;
    while(c!=NULL)
    {
        cout<<c->info<<endl;
        c= c->next;
    }
}

void search() {
    int x;

    cout<<"enter number to search"<<endl;
    cin>>x;
    node *temp=start;
    while(temp!=NULL) {
        if(temp->info ==x)
    {
        cout<<"adress of number is:"<< temp<<endl;
        break;

    }
    temp = temp->next;
    }
    if(temp==NULL) {
    cout<<"element not found"<<endl;
    }
}

