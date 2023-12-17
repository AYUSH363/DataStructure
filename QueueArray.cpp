#include <iostream>
using namespace std;

struct Student
{
    int num;
    char name[50];
};
Student q[5];
int front, rear;

void Insert();
void Delete();
void Display();

int main()
{
    front = rear = -1;
    int ch;
    do
    {
        cout << "1 for insert" << endl;
        cout << "2 for delete" << endl;
        cout << "3 for display" << endl;
        cout << "4 for exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            Insert();
            break;
        case 2:
            Delete();
            break;
        case 3:
            Display();
            break;
        }
    } while (ch != 4);
}

void Insert()
{
    if (rear == 4)
    {
        cout << "overflow" << endl;
        return;
    }
    Student s;
    cout << "Enter num and name" << endl;
    cin >> s.num;
    cin>>s.name;

    if (rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
        q[rear] = s;
    }
}
void Delete()
{
    if (front == -1)
    {
        cout << "underflow" << endl;
        return;
    }
    cout << q[front].num << endl;
    cout << q[front].name << endl;
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

void Display()
{
    if (front == -1)
    {
        cout << "empty" << endl;
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        cout << q[i].num << endl;
        cout << q[i].name << endl;
    }
}
