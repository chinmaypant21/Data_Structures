#ifndef LIST_H //Include Guard
#define LIST_H

// #include<iostream>
// using namespace std;

namespace cpp{
    template <class> class List;
    template <class> class Node;
}


template <class T>
class cpp::Node
{
    protected:
    T data;
    Node *next;

    Node(T value)
    {
        this->data=value;
        next = NULL;
    }

    template<class> friend class List;
};

template <class T>
class cpp::List
{
    private:
    Node<T> *head;
    Node<T> *tail;
    int list_length = 0;
    
    public:
    List(){}
    List(T value)
    {
        Node <T> *newNode = new Node<T>(value);
        this->head = this->tail = newNode;
        tail->next=NULL;
        this->list_length++;
    }

    void push(T value);
    void pop();
    void insert(int index,T value);
    T at(int index);
    T remove(int index);
    List reverse();

};

template<class T> void cpp::List<T>::push(T value)
{
    Node <T> *new_node = new Node<T>(value);
    this->tail->next = new_node;
    this->tail = new_node;
    new_node->next = NULL;
    if(list_length==0) this->head = new_node;
    this->list_length++;
}

template<class T> void cpp::List<T>::pop()
{
    
}

template<class T> void cpp::List<T>::insert(int index, T value)
{
    
}

template<class T> T cpp::List<T>::at(int index)
{
    if(index<0 || index>=this->list_length)
    {
        /*Exception Handle*/
    }

    Node<T> *current = this->head;
    for(int i=0;i<index;i++)
    {
        current = current->next;
    }

    return current->data;
}

template<class T> T cpp::List<T>::remove(int index)
{
    
}

template<class T> cpp::List<T> cpp::List<T>::reverse()
{
    List<T> reverse_list;
    /* ---- */
    return reverse_list;
}

#endif /* LIST_H */