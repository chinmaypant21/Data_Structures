#include <iostream>
#include "List.h"
using namespace std;

class Stack
{
    int size;
    Node *top;
    List data;

    public:
    Stack(int size)
    {
        this->size = size;
        this->top  = NULL;
    }

    void push(int element)
    {
        if(isFull())
            return;

        top = data.insert(0,element);
        
    }

    int pop()
    {
        if(isEmpty())
            return -1;

        top = data.remove(0);
        return top->get_data();
    }

    bool isFull()
    {
        if (this->data.len() == this->size)
            return true;
        return false;

    }

    bool isEmpty()
    {
        if (this->data.len() == 0)
            return true;
        return false;
    }

    inline void display()
    {
        data.display();
    }
};


int main()
{
    string text = "console.log('Hello there its a normal text')))\n"
                  "function fun(e){{return e})";

    Stack parenthesis(text.size());
    Stack curly_bracket(text.size());

    int col_counter = 1,line_counter = 1;
    for(char i:text)
    {
        if(i=='(')
            parenthesis.push(1);
        else if(i==')')
        {
            if(parenthesis.pop() == -1)
            {
                cout<<"\n[-]Parenthesis not opened properly at col "<<col_counter;
                cout<<" and line "<<line_counter<<endl;
            }
        }

        else if(i=='{')
            curly_bracket.push(1);
        
        else if(i=='}')
        {
            if(curly_bracket.pop() == -1)
            {
                cout<<"\n[-]Curly Brackets not opened properly at col "<<col_counter;
                cout<<" and line "<<line_counter<<endl;
            }
        }

        else if(i=='\n')
        {
            line_counter++;
            col_counter=0;
        }

        col_counter++;
    }

    if(!parenthesis.isEmpty())
        cout<<"\n[-]Parenthesis not closed properly\n";

    if(!curly_bracket.isEmpty())
        cout<<"\n[-]Curly Brackets not closed properly\n";
}