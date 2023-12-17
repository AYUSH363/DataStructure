#include<iostream>
using namespace std;

struct Node
{
    int info;
    Node *next;
};
Node *front , *rear;

void Insert();
void Delete();
void Display();

int main()
{
    front = rear = NULL;
    int ch;
    do
    {
        cout << "1 for insert" << endl;
        cout << "2 for delete" << endl;
        cout << "3 for display" << endl;
        cout << "4 for exit" << endl;
        cin >> ch;
        switch(ch)
        {
            case 1: Insert();
            break;
            case 2: Delete();
            break;
            case 3: Display();
            break;
        }
    }
    while(ch != 4);
}

void Insert()
{
    Node *s = new Node;
    cout << "enter info" << endl;
    cin >> s -> info;
    s -> next = NULL;
    
    if(rear == NULL)
    {
        front = rear = s;
    }
    else{
        rear -> next = s;
        rear = s;
    }
}

void Delete()
{
    if(front == NULL)
    {
        cout << "underflow" << endl;
        return;
    }
    Node *n = front;
    cout << n -> info << endl;
    if(front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front -> next;
    }
    delete n;
}

void Display()
{
    if(front == NULL)
    {
        cout << "Queue empty" << endl;
        return;
    }
    Node *n = front;
    while(n != NULL)
    {
        cout << n -> info << endl;
        n = n -> next;
    }
}
