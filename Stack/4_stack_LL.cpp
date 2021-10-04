#include <iostream>
#include "List.h" //List Class is created under "List.h" file
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
        {
            cout<<"Can not push to full stack\n";
            return;
        }

        top = data.insert(0,element);
        
    }

    int pop()
    {
        if(isEmpty())
        {
            cout<<"Can not pop from an empty stack\n";
            return -1;
        }
        top = data.remove(0);
        return top->get_data();
    }

    bool isFull()
    {
        /*Using linked List, we can also create Stacks which have no size limit
         and we can continue creating nodes UNTIL HEAP MEMORY IS FULL
         in that case, we could write condition insize List like:
         Node *newNode = new Node(value);
         if (t==NULL) {List FUll because no more space in heap memory left}

         But here we have created Fixed size stack so we need to calculate according to number of elements in List*/

        if (this->data.len() == this->size)
            return true;
        return false;

    }

    bool isEmpty()
    {
        if (this->data.len() == 0)
        {
            return true;
        }
        return false;
    }

    void display()
    {
        data.display();
    }
};

int main()
{
    Stack s(5);
    s.push(1);
    s.push(4);
    s.push(5);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.display();

}