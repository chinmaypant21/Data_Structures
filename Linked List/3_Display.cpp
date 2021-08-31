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

    /**
     * insert method takes a value (data) as parameter.
     * It creates a newnode object of type node with data=value
     * Currently tail is the last element of list, and we set next of the tail to point to newNode
     * Now the end node = newNode thus it points tail to newnode
     */
    void insert(int value)
    {
        Node *newNode = new Node(value);
        this->tail->next = newNode;
        this->tail = newNode;
        newNode->next = NULL;
        this->length++;
    }

    /*
    We can display the Linked List by either iterative method or recursive method
    */
    void displayIterative()
    {
        /*It is just like displaying an array using loop 
        and printing element at 'i'th index then incrementing i*/
        Node *current = this->head;
        while(current != NULL)
        {
            cout<<current->data<<" "; 
            current = current->next;
        }
    }

    void recursivePrinter(Node *current)
    {
        cout<<current->data<<" ";
        if (current->next != NULL) 
        recursivePrinter(current->next);
    }

    /**
     * @param start node from where to begin printing values
     */
    void displayRecursive(Node *start=NULL)
    {
        if(start==NULL) start=this->head; 
        recursivePrinter(start);
    }
};

int main()
{
    List l(5);
    l.insert(6);
    l.insert(7);
    l.displayIterative();
    l.displayRecursive();
}