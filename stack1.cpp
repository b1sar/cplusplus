#include <iostream>
using namespace std;

class Node
{
    public:
    int arr[10];
    int top;

    Node()
    {
        top = 0;
    }
    void push(int deger)
    {
        if(top < 10)
        {
            arr[top] = deger;
            top++;
        }else
        {
            cout<<"Stack is overflow"<<endl;
        }

    }

    void pop()
    {
        if(!empty())
        {
            top--;
        }else
        {
            cout<<"Stack is underflow"<<endl;
        }
    }

    void display()
    {
        cout<<"------------"<<endl;
        for(int i = top-1; i>=0; i--)
            cout<<arr[i]<<endl;
            cout<<"----------"<<endl;
    }

    bool empty()
    {
        if(top==0)
            return true;
        else
            return false;
    }
};

int main()
{
    Node a;
    int deg = 5;
    while(deg!=0)
    {
        cout<<"1- Push()"<<endl;
        cout<<"2- Pop()"<<endl;
        cout<<"3- Display()"<<endl;
        cout<<"0- to quit"<<endl;
        cout<<"#####################"<<endl;
        int aradeg;
        cin>>aradeg;
        switch(aradeg)
        {
            case 1:
                int temp;
                cout<<"type the value to add"<<endl;
                cin>>temp;
                a.push(temp);
                break;
            case 2:
                a.pop();
                break;
            case 3:
                a.display();
                break;
            case 0:
                deg = aradeg;
                break;
        }
        
    }
}