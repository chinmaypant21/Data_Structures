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

    void insert(int value,int index)
    {
        if(index > this->length || index<0){
            cout<<("\nInvalid index for insert method\n");
            return;
        }

        Node *newNode = new Node(value);
        Node *index_pointer = this->head;
        this->length++;
        
        /*If we have to insert at head, in that case there is no element before that
        so we have to change the statement for this case*/

        if(index==0) 
        {
            newNode->next=this->head;
            this->head=newNode;
            return;
        }

        for(int i=0;i<index-1;i++)
        {
            index_pointer = index_pointer->next;
        }
        newNode->next=index_pointer->next;
        index_pointer->next=newNode;
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
    {   //Min -> O(1)    Max -> O(n)
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
    l.push(1);
    l.push(9);
    l.insert(4,0);
    l.display();
}