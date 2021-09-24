#include <iostream>
using namespace std;

class Node
{
    public:
    int data; 
    Node *next;
    Node *previous;
    /*In a Singly linked list, there is only one pointer that points to the next of the element
    due to this reason, node was not able to access the element previous to that element
    In a doubly linked list, have two pointers previous and next which keeps track of the node
    previous to the current node and node after the current node in the List, thus it is DOUBLY LINKED.*/

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
        this->length--;
        /*In a DLL, pop has became much more easy than in SLL because of the 
        availability of "previous node pointer"*/
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
    dll.pop();
    dll.display();

}