#include<iostream>
using namespace std;

int info[5];

void push();
void pop();
void disp();

int top = -1;

int main(){
    
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

void push() {
    if(top==4) {
        cout<<"overflow"<<endl;
        return;
    }

    int m;
    cout<<"enter info"<<endl;
    cin>>m;
    top++;
    info[top] = m;

}

void pop(){
    if(top== -1) {
        cout<<"underflow"<<endl;
        return;
    }

    cout<<info[top];
    top--;
}

void disp() {
    if(top == -1){
        cout<<"underflow"<<endl;
        return;
    }
for(int i =top;i>=0;i--) {
    cout<<info[i]<<" "<<endl;
}
}


