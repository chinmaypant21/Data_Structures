#include <iostream>
#include "List.h"
using namespace std;

int num_operators = 4;
char operator_array[] = {'+','-','*','/'};
int precedence_val_arr[] = {1,1,2,2};

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

int precedence(char opr)
{
    for(int i=0; i<num_operators; i++)
    {
        if(operator_array[i] == opr)
            return precedence_val_arr[i];
    }
    return -1;
}

int main()
{
    // string statement = "a*d/e-b+c";
    string statement = "a+b*c-d/e";
    string postfix = "";
    Stack operator_precedence_stack(statement.length());

    for(int i=0; i<statement.length(); i++)
    {
        if(isOperator(statement[i]))
        {
            cout<<"isoperator: "<<statement[i]<<endl;
            if(precedence(statement[i]) > precedence(operator_precedence_stack.atTop()))
            {
                operator_precedence_stack.push(statement[i]);
            }

            else
            {
                while(true)
                {
                    if(precedence(statement[i])>precedence(operator_precedence_stack.atTop()))
                    {
                        operator_precedence_stack.push(statement[i]);
                        break;
                    }

                    else
                    {
                        postfix+=operator_precedence_stack.pop();
                    }
                }
            }             
        }

        else
        {
            postfix+=statement[i];
        }
    }
    
    while(operator_precedence_stack.atTop())
    {
        postfix+= operator_precedence_stack.pop();
    }
    cout<<"\nInfix: "<<statement<<endl<<"Postfix: "<<postfix<<endl;
}

