#include <iostream>
using namespace std;

class Node
{
    public:
    int data; //Generally Size of int is 4 bytes
    Node *next;
    /**
     * @brief 
     *  Pointers store the address of data objects they are pointing to.
     *  Size of pointer on a 64 bit system is 64 bits (or 8 bytes) and 4bytes for 32bit system.
     *  Here the 'next' pointer can store the address of a Node type object.
    */
};

class List //This is the LinkedList
{
    Node *head; // head Pointer is stored in the stack memory and is referencing the Node type object in the heap memory
    Node *tail;
    int length {};
};

int main()
{
    /* This is to show the size taken by node and its members*/
    Node n;
    cout<<sizeof(n)<<endl;
    cout<<sizeof(n.data)<<endl;
    cout<<sizeof(n.next);
}