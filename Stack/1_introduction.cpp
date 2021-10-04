#include <iostream>
using namespace std;

class Stack
{
    /**
     * In a stack, we add and remove elements only from the top of the stack.
     * For implementing a stack, we need the size of stack, top pointer of stack to maintain
     * operations and a data structure (like array or linked list) to store elements.
     */
    int size;
    int top;
    int *data;

    public:
    Stack(int size)
    {
        this->size = size;
        this->top  = -1; //when stack is empty so the top pointer will not pointing to any location of stack
        this->data  = new int[size];
    }


};

int main()
{
    Stack s(5);
}