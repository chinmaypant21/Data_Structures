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
};

class DLList 
{
    Node *head; 
    Node *tail;
    int length {};
};

int main()
{
    Node n;
}