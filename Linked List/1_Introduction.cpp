#include <iostream>
using namespace std;

class Node
{
    public:
    int data; //Generally Size of int is 4 bytes
    Node *next;
    /* Pointers store the address of data objects they are pointing to.
    Size of pointer on a 64 bit system is 64 bits (or 8 bytes) and 4bytes for 32bit system.
    Here the 'next' pointer can store the address of a Node type object.*/
};

class List
{
    Node *head;
    Node *tail;
    Node *current;
    int length {};
};

int main()
{
    Node n;
    cout<<sizeof(n)<<endl;
    cout<<sizeof(n.data)<<endl;
    cout<<sizeof(n.next);
}