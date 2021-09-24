#include <iostream>
using namespace std;

class Node
{
    public:
    int data; 
    Node *next;
    Node *previous;
    Node(int value=0)
    {
        this->data=value;
        next = NULL;
        previous = NULL;
    }
};

class DLList 
{
    Node *head; 
    Node *tail;
    int length {};

    public:
    DLList(int value=0)
    {
        Node *newNode = new Node(value);
        this->head = newNode;
        this->tail = newNode;
        newNode->next = NULL;
        newNode->previous = NULL;
        this->length++;
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        this->tail->next = newNode;
        newNode->previous=tail;
        this->tail = newNode;
        newNode->next = NULL;
        this->length++;
    }

    void reverse()
    {
        Node *current = this->head;
        this->tail = this->head;
        for(int i=0;i<length;i++)
        {
            swap(current->previous,current->next);
            if(current->previous!=NULL) current = current->previous;
        }
        this->head=current;
    }

    void reverse_tail()
    {
        Node *current = this->tail;
        head = this->tail;
        for(int i=0;i<length;i++)
        {
            swap(current->previous,current->next);
            if(current->next!=NULL) current = current->next;
        }
    }

    void display()
    {
        Node *current = this->head;
        while(current != NULL)
        {
            cout<<current->data<<" "; 
            current = current->next;
        }
        cout<<endl;
    }


};

int main()
{
    DLList dll(1);
    dll.push(5);
    dll.push(2);
    dll.push(9);
    dll.display();
    dll.reverse();
    // dll.reverse_tail();
    dll.display();
}