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

    //Merging two Sorted LinkedList
    void merge(List l2)
    {
        /**
         * Initially Pointer first will point to the head of current LinkedList
         * Initially Pointer second will point to the head of second LinkedList.
         */
        Node *first = (*this).head;
        Node *second = l2.head;

        /**
         * Because we are merging sorted Lists, so our current head should point
         * to the element which is smaller in the of the two elements of both Lists.
         */
        if(first->data < second->data)  first = first->next; //initially head is already same as first
        else
        {
            this->head = second;
            second = second->next;
        }
        //This last pointer will point to the element before 'first' or 'second' pointer and 
        //it will help to make nodes point in such a way that the resultant list is all sorted
        Node *last = this->head;
        last->next = NULL;
        
        while(first != NULL and second != NULL)
        {
            /*If value at the Node to which first pointer is pointing is 
            greater that the value for second, then the node after the last node should be 
            the second one because its value is smaller than the first one.
            And after this, the 'last' pointer will point to the second Node and
            'second' pointer will point to the next node of current node.*/
            if(first->data>second->data)
            {
                last->next=second;
                last = second;
                second = second->next;
            }

            else
            {
                last->next=first;
                last = first;
                first = first->next;
            }
        }

        last->next = NULL;
        /*Now, if any of the pointers pointing first or second list are not null,
        It means that some values are still remaining in that List.
        So we point out next pointer of out last node to that Node(because definitely, the value(s))
        that are remaining in that node are greater that the value at last node and all Lists are sorted.*/
        if(first!=NULL) last->next=first;
        else if(second!=NULL) last->next=second;
    }
};

int main()
{
    List l(2);
    l.push(3);
    l.push(4);
    l.push(6);

    List l2(1);
    l2.push(3);
    l2.push(5);
    l2.push(7);

    l.merge(l2);
    l.display();
    return 0;
}