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
    public:
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

    /* For removing Node from a given index we have to assign the next pointer of the previous node
        from the index node to the next node of the index node, due to which index node will be thrown out
        of the linked list.
        previous->next = index->next  ::: previous-> next = previous->next->next
    */
    void remove(int index)
    {
        if(index > this->length-1 || index<0){
        cout<<("\nInvalid index for remove method\n");
        return;
        }
        this->length--;

        if(index==0)
        {
            this->head=this->head->next;
            return;
        }

        Node *index_pointer = this->head;
        for(int i=0;i<index-1;i++) index_pointer = index_pointer->next;
        index_pointer->next = index_pointer->next->next;
        if(index_pointer->next==NULL) this->tail = index_pointer;
    }
};

int main()
{
    List l(2);
    l.push(3);
    l.push(4);
    l.push(6);
    l.remove(3);
    l.display();
    return 0;
}