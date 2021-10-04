#ifndef LIST_H_
#define LIST_H_
#include <iostream>
/*LIST FOR PERFORMING STACK OPERATIONS*/
class Node
{
    protected:
    int   data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }

    public:
    inline int get_data()
    {
        return this->data;
    }

    friend class List;

};

class List
{
    private:
    Node *head;
    Node *tail;
    int list_length = 0;
    
    public:
    List(){}
    List(int value)
    {
        Node *newNode    = new Node(value);
        this->head       = newNode;
        this->tail       = newNode;
        this->tail->next = NULL;
        this->list_length++;
    }

    Node* insert(int index, int value)
    {
        if(index > this->list_length || index<0)
        {
            std::cerr << "exception: cpp::List 'insert' method:  passed index '"
                    << index << "' not in index range [0," 
                    << this->list_length << "]\n";
            exit(-1);
        }

        Node *newNode       = new Node(value);
        Node *index_pointer = this->head;
        if(index == this->list_length) 
            this->tail = newNode;

        this->list_length++;
        if(index==0) 
        {
            newNode->next = this->head;
            this->head    = newNode;
            this->tail    = newNode;
            return newNode;
        }

        for(int i=0; i<index-1; i++)
        {
            index_pointer = index_pointer->next;
        }
        newNode->next       = index_pointer->next;
        index_pointer->next = newNode;
        return newNode;
    }

    Node* remove(int index)
    {
        if(index > this->list_length-1 || index<0){
            std::cout<<("\nInvalid index for remove method\n");
            return NULL;
        }
        this->list_length--;

        if(index==0)
        {
            Node *return_node = this->head;
            this->head=this->head->next;
            return return_node;
        }

        Node *index_pointer = this->head;
        for(int i=0;i<index-1;i++) index_pointer = index_pointer->next;
        Node *return_node = index_pointer->next;
        index_pointer->next = index_pointer->next->next;
        if(index_pointer->next==NULL) this->tail = index_pointer;

        return return_node;
    }

    int len()
    {
        return list_length;
    }

    void display()
    {
        Node *current = this->head;
        if (current == NULL)
        {
            std::cout<<"[]\n";
            return;
        }
        while(current != NULL)
        {
            std::cout<<current->data<<"\n"; 
            current = current->next;
        }
    }
};


#endif /*LIST_H_*/