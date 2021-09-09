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
    int length {};

    public:
    Node *head;
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

    // N elements copied from LL to array, then N elements copied from array to LL,
    // thus Time Complexity = O(2n) = O(n)
    void reverse_data()
    {
        int data_array[this->length] {0};
        Node *current=this->head;
        int i=0;
        while(current!=NULL)
        {
            data_array[i++]=current->data;
            current=current->next;
        }
        current=this->head;
        while(current!=NULL)
        {
            current->data=data_array[--i];
            current=current->next;
        }
    }

    void reverse_nodes()
    {
        /* Reversing using slider Pointers method.*/
        /**
         * @brief In this method, we create thiree pointers, one pointing to the
         * current element we are working on, one on the previous element, and one on the next element
         * At starting prev and curr pointer are pointing to NULL, and after pointer to head
         * then we slide pointers to next location and while doing it, we point the 'next' of current to 
         * previous. We do this untill 'after' pointer gets to NULL.
         */
        Node *previous = NULL;
        Node *current = NULL;
        Node *after = head;
        while(after!=NULL)
        {
            previous=current;
            current=after;
            after=after->next;
            current->next=previous;
        }
        head=current;
    }

    void reverseRecursion()
    {
        reverse_recursion_method(NULL,this->head);
    }

    void reverse_recursion_method(Node *previous,Node *current)
    {
        if(current==NULL)
        {
            this->head=previous;
            return;
        }
        reverse_recursion_method(current,current->next);
        current->next=previous;
    }
};

int main()
{
    List l(2);
    l.push(3);
    l.push(4);
    l.push(6);
    Node *n=NULL;
    l.reverseRecursion();
    l.display();
    return 0;
}