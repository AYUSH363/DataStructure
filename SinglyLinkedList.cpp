#include<iostream>
using namespace std;

class node {
    public:
    int info;
    node *next;
};
node *start1,*last1,*start2, *last2;
void insert1();
void Delete1();
void disp1();

void insert2();
void Delete2();
void disp2();

void concatenate();

int main() {
    start1 = last1 =start2  = last2= NULL;
    int ch;
    do{
        cout<<"press 1 to insert in first list"<<endl;
        cout<<"press 2 to delete in first list"<<endl;
        cout<<"press 3 to display in first list"<<endl;
        cout<<"press 4 to insert in second linkedlist"<<endl;
        cout<<"press 5 to delete in second linkedlist"<<endl;
        cout<<"press 6 to display in second linkedlist"<<endl;
        cout<<"press 7 to concatenate "<<endl;
        cout<<"press 8 to exit "<<endl;
        


        cin>>ch;
        switch(ch)
        {
            case 1: 
            insert1();
            break;
            case 2:
            Delete1();
            break;
            case 3:
            disp1();
            break;
            case 4: 
            insert2();
            break;
            case 5:
            Delete2();
            break;
            case 6:
            disp2();
            break;
            case 7:
            concatenate();
            break;

        }
        
    }
    while(ch!=8);


}

void insert1() {
    node *n = new node;
    cout << "enter info: ";
    cin >> n->info;
    n->next = NULL;

    if (start1 == NULL) {
        start1 = last1 = n;
        return;
    }
    node *p = NULL, *c = start1;
    while (c != NULL) {
        if (c->info > n->info) {
            break;
        }
        p = c;
        c = c->next;
    }
    if (c == start1) {
        n->next = start1;
        start1 = n;
    } else if (c == NULL) {
        last1->next = n;
        last1 = n;
    } else {
        p->next = n;
        n->next = c;
    }
}

void insert2() {
    node *n = new node;
    cout << "enter info: ";
    cin >> n->info;
    n->next = NULL;

    if (start2 == NULL) {
        start2 = last2 = n;
        return;
    }
    node *p = NULL, *c = start2;
    while (c != NULL) {
        if (c->info > n->info) {
            break;
        }
        p = c;
        c = c->next;
    }
    if (c == start2) {
        n->next = start2;
        start2 = n;
    } else if (c == NULL) {
        last2->next = n;
        last2 = n;
    } else {
        p->next = n;
        n->next = c;
    }
}


void Delete1() {
    if (start1 == NULL) {
        cout << "No elements to delete" << endl;
        return; // Return early when there are no elements to delete
    }

    int m;
    cout << "Enter info to be deleted: ";
    cin >> m;

    node *p = NULL, *c = start1;

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

    if (c == start1) {
        start1 = start1->next;
    } else if (c == last1) {
        p->next = NULL;
        last1 = p;
    } else {
        p->next = c->next;
    }

    delete c;
}

void Delete2() {
    if (start2 == NULL) {
        cout << "No elements to delete" << endl;
        return; // Return early when there are no elements to delete
    }

    int m;
    cout << "Enter info to be deleted: ";
    cin >> m;

    node *p = NULL, *c = start2;

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

    if (c == start2) {
        start2 = start2->next;
    } else if (c == last2) {
        p->next = NULL;
        last2 = p;
    } else {
        p->next = c->next;
    }

    delete c;
}



void disp1() {
    node *c;
    c = start1;
    while(c!=NULL)
    {
        cout<<c->info<<endl;
        c= c->next;
    }
}

void disp2() {
    node *c;
    c = start2;
    while(c!=NULL)
    {
        cout<<c->info<<endl;
        c= c->next;
    }
}


void concatenate() {
    last1 -> next =start2;
    last1=last2;


}

    
    
