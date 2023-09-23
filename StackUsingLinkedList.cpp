#include<iostream>
using namespace std;

class Node {
    public:
    int info;
    Node *next;

};
Node *top;
int main() {


void push();
void pop();
void disp();

top=NULL;
int ch;
do{
    cout<<"Press 1 to push"<<endl;
    cout<<"Press 2 to pop"<<endl;
    cout<<"Press 3 to display"<<endl;
    cout<<"Press 4 to exit"<<endl;
    cin>>ch;

    switch(ch ){
        case 1 : push();
        break;
        case 2: pop();
        break;
        case 3:disp();
        break;

    }
}
while(ch!=4);
}

void push(){

    Node *n = new Node();
    cout<<"enter info"<<endl;
    cin>>n->info;
    n->next = NULL;
    

if(top == NULL){
    top = n;
}
else {
    n->next = top;
    top = n;
}
}

void pop(){
    if(top == NULL){
        cout<<"underflow"<<endl;
        return;
    }

Node *n = top;
cout<<n->info<<endl;
top = top -> next;
delete n;
}

void disp() {
    if(top == NULL){
        cout<<"empty stack"<<endl;
        return;
    }

Node * n = top;
while (n!=NULL) {
    cout<<n->info<<endl;
    n=n->next;
}
}

