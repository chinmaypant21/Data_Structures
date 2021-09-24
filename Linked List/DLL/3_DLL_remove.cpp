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

    void remove(int index)
    {
        if(index > this->length-1 || index<0)
        {
            cout<<("\n[-]Invalid index for remove method\n");
            return;
        }

        this->length--;
        Node *current = this->head;
        if(index==0)
        {
            this->head = this->head->next;
            if(head!=NULL) this->head->previous=NULL;
            delete current;
            return;
        }
        /*
        Here we are going to the node which we have to remove and then assigning the
        "next" pointer of previous node to current's next and "previous" of  next node
        to current's previous node.

        We could also have done this by going to the element previous to the index element
        and set its next to next's next (means we are just kicking out the given index element)
        and current->next->previous to current.
        */
        for(int i=0;i<index;i++)
        {
            current = current->next;
        }

        current->previous->next = current->next;
        if (current->next!=NULL)  //if curent is not the last node of DLL
        {
            current->next->previous=current->previous;
        }

        else this->tail = current->previous;
        delete current;
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
    dll.remove(0);
    dll.display();
}