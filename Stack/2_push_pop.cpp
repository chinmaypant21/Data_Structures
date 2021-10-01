#include <iostream>
using namespace std;

class Stack
{
    int size;
    int top;
    int *data;

    public:
    Stack(int size)
    {
        this->size = size;
        this->top  = -1;
        this->data  = new int[size];
    }

    void push(int element)
    {
        if(isFull())
        {
            cout<<"Can not push to already full stack";
            return;
        }

        top++;
        this->data[top] = element;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Can not pop from an empty stack";
            return;
        }
        top--;
    }

    //if top is less than 0 it means it is not poiting to any element of stack 
    //thus stack is empty
    bool isEmpty()
    {
        if (this->top < 0)
            return true;
        return false;
    }

    bool isFull()
    {
         if (this->top == this->size-1)
            return true;
        return false;

    }

    void display()
    {
        cout<<"[ ";
        for(int i=0;i<=top;i++)
        {
            cout<<data[i]<<", ";
        }
        cout<<"]";
        cout<<endl;
    }
};

int main()
{
    Stack s(5);
    s.push(1);
    s.push(4);
    s.push(3);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.display();
}