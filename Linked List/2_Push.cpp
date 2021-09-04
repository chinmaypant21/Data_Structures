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
    Node *head;
    Node *tail;
    int length {};

    public:
    List(int value=0)
    {
        Node *newNode = new Node(value);
        this->head = newNode;
        this->tail = newNode;
        this->length++;
    }

    /**
     * push method takes a value (data) as parameter.
     * It creates a newnode object of type node with data=value
     * Currently tail is the last element of list, and we set next of the tail to point to newNode
     * Now the end node = newNode thus it points tail to newnode
     */
    void push(int value)
    {
        Node *newNode = new Node(value);
        this->tail->next = newNode;
        this->tail = newNode;
        newNode->next = NULL;
        this->length++;
    }
};

int main()
{
    List l(5);
    l.push(6);
    l.push(7);
}