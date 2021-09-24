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

    void insert(int index, int value) // min O(1) max O(n)
    {
        if(index > this->length || index<0)
        {
            cout<<("\n[-]Invalid index for insert method\n");
            return;
        }

        Node *newNode = new Node(value);
        if(index==this->length) this->tail=newNode;
        this->length++;
        if(index==0)
        {
            newNode->next = head;
            head->previous = newNode;
            newNode->previous = NULL;
            head = newNode;
            return;
        }

        Node *current = head;
        for(int i=1;i<index;i++)
        {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->previous = current;
        if(current->next != NULL) current->next->previous = newNode;
        current->next = newNode;
    }

};

int main()
{
    DLList dll(1);
    dll.push(5);
    dll.push(2);
    dll.push(9);
    dll.display();
    dll.insert(0,6);
    dll.display();
    dll.insert(2,11);
    dll.insert(6,15);
    dll.display();
}