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

    void push(int value) //O(1)
    {
        Node *newNode = new Node(value);
        this->tail->next = newNode;
        newNode->previous=tail;
        this->tail = newNode;
        newNode->next = NULL;
        this->length++;
    }

    void pop() //O(1)
    {
        this->tail  = this->tail->previous;
        this->tail->next = NULL;
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

    void insert(int index, int value)
    {
        
    }

};

int main()
{
    DLList dll(1);
    dll.push(5);
    dll.push(2);
    dll.push(9);
    dll.display();
    dll.pop();
    dll.display();

}