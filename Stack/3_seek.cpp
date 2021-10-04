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

    int seek(int index)
    {
        if(index<0 || index>=size)
        {
            cout<<"\nWrong Index\n";
            return -1;
        }

        return data[index];
    }
};

int main()
{
    Stack s(5);
    s.push(1);
    s.push(4);
    s.push(3);
    s.display();
    cout<<endl<<s.seek(2)<<endl;

}