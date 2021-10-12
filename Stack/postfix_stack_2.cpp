#include <iostream>
using namespace std;

#define NUM_OPERATORS 7
char operator_array[] = {'+','-','*','/','^','(',')'};
int out_precedence_val[] = {1,1,3,3,6,7,0};
int in_precedence_val[]  = {2,2,4,4,5,0};

class Stack
{
    int size;
    int top;
    char *data;

    public:
    Stack(int size)
    {
        this->size = size;
        this->top  = -1;
        this->data  = new char[size];
    }

    void push(char element)
    {
        if(isFull())
        {
            cout<<"Can not push to already full stack";
            return;
        }

        top++;
        this->data[top] = element;
    }

    char pop()
    {
        if(isEmpty())
        {
            cout<<"Can not pop from an empty stack";
            return -1;
        }
        return data[top--];
    }

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

    char atTop()
    {
        if (top != -1)
            return data[top];

        else return '\0';
    }

    int len()
    {
        return top+1;
    }
};

inline bool isOperator(char c)
{
    for(char i :operator_array)
    {
        if(i == c)
            return true;
    }
    return false;
}

int in_precedence(char opr)
{
    for(int i=0; i<NUM_OPERATORS; i++)
    {
        if(operator_array[i] == opr)
            return in_precedence_val[i];
    }
    return -1;
}

int out_precedence(char opr)
{
    for(int i=0; i<NUM_OPERATORS; i++)
    {
        if(operator_array[i] == opr)
            return out_precedence_val[i];
    }
    return -1;

}


int main()
{
    string statement = "((a+b)*c)-d^e^f";
    string postfix = "";
    Stack operator_stack(statement.length());
    for(int i=0;i<statement.length();i++)
    {
        if(isOperator(statement[i]))
        {
            if(statement[i]==')')
            {
                while(in_precedence(operator_stack.atTop()) != out_precedence(statement[i]))
                {
                    postfix+=operator_stack.pop();
                }
                operator_stack.pop();
            }

            else if(out_precedence(statement[i]) > in_precedence(operator_stack.atTop()))
            {
                operator_stack.push(statement[i]);
            }

            else
            {
                while(out_precedence(statement[i]) < in_precedence(operator_stack.atTop()))
                {
                    postfix+=operator_stack.pop();
                }
                operator_stack.push(statement[i]);
            }
        }

        else postfix+=statement[i];
    }
    
    while(operator_stack.atTop())
        postfix+= operator_stack.pop();

    cout<<"\nInfix: "<<statement<<endl<<"Postfix: "<<postfix<<endl;
}

