#include<iostream>
using namespace std;

void SelectionSort();
void BubbleSort();
void InsertionSort();

int i ,j,t;
int a[5];
int main() 
{
 
    for(int i=0;i<5;i++) {
        cin>>a[i];

    }
    int ch;

    do {
        cout<<"press 1 for selection sort"<<endl;
        cout<<"press 2 for bubble sort"<<endl;
        cout<<"press 3 for insertion sort"<<endl;
        cout<<"press 4 for exit"<<endl;

        cin>>ch;
        switch(ch) 
        {
            case 1 : SelectionSort();
            break;
            case 2 : BubbleSort();
            break;
            case 3 : InsertionSort();
            break;

        }
        



    }
    while(ch!=4);

}

void SelectionSort() 
{
    
int mi,m;
for(int i=0;i<4;i++){
    mi=i;
    m = a[i];
    for(j=i+1;j<5;j++)
    {
        if(a[j] < m) 
        {
            m = a[j];
            mi = j;
        }
    }
    t = a[i];
    a[i] = m;
    a[mi] = t;
}

cout<<"sorted values as"<<endl;
for(i=0;i<5;i++){
    cout<<a[i]<< " ";
}
}




void BubbleSort(){

int mi,m;
for(i = 0;i<4;i++) 
{
    for(j=0;j<4-i;j++) 
    {
        if(a[j] > a[j+1]) 
        {
            t =a[j];
            a[j] = a[j+1];
            a[j+1] = t;
        }
    }
}


cout<<"sorted values as"<<endl;
for(i=0;i<5;i++){
    cout<<a[i]<< " ";
}

}

void InsertionSort() {

    int mi, m;
    for (i = 1; i < 5; i++)
    {
        if (a[i] < a[i - 1])
        {
            t = a[i];
            j = i - 1;
            while (j >=0 && a[j] > t)
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = t;
        }
    }

    cout << "sorted values as" << endl;
    for (i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
}
