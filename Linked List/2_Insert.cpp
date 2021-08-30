#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next = NULL;
    Node(int value=0)
    {
        this->data=value;
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
    }

    void insert(int value)
    {
        Node *newNode = new Node(value);
        this->tail->next = newNode;
        this->tail = newNode;
        newNode->next = NULL;
    }
};

int main()
{
    List l(5);
    l.insert(6);
    l.insert(7);
}