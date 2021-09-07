#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node(int value=0)
    {
        this->data=value;
        next = NULL;
    }
};

class List
{
    Node *tail;
    Node *head;
    int length {};

    public:
    List(int value=0)
    {
        Node *newNode = new Node(value);
        this->head = newNode;
        this->tail = newNode;
        this->length++;
    }

    void display()
    {
        Node *current = this->head;
        while(current != NULL)
        {
            cout<<current->data<<" "; 
            current = current->next;
        }
    }

    void push(int value)
    {   
        Node *newNode = new Node(value);
        this->tail->next = newNode;
        this->tail = newNode;
        newNode->next = NULL;
        this->length++;
    }

    //Merging two Sorted LinkedList
    void merge(List l2)
    {
        Node *first = (*this).head;
        Node *second = l2.head;

        if(first->data < second->data)  first = first->next;
        else
        {
            this->head = second;
            second = second->next;
        }

        Node *last = this->head;
        last->next = NULL;
        
        while(first != NULL and second != NULL)
        {
            if(first->data>second->data)
            {
                last->next=second;
                last = second;
                second = second->next;
            }

            else
            {
                last->next=first;
                last = first;
                first = first->next;
            }
        }
        
        last->next = NULL;
        if(first!=NULL) last->next=first;
        else if(second!=NULL) last->next=second;
    }
};

int main()
{
    List l(2);
    l.push(3);
    l.push(4);
    l.push(6);

    List l2(1);
    l2.push(3);
    l2.push(5);
    l2.push(7);

    l.merge(l2);
    l.display();
    return 0;
}