#ifndef LIST_H //Include Guard
#define LIST_H

#include <iostream>
// using namespace std;

namespace cpp{
    template <class> class List;
    template <class> class Node;
}

template<class T> std::ostream& operator << (std::ostream&, const cpp::List <T>&);//prototype

template <class T>
class cpp::Node
{
    protected:
    T     data;
    Node *next;

    Node(T value)
    {
        data = value;
        next = NULL;
    }

    template<class> friend class List;
    template<class U> friend std::ostream& ::operator<< (std::ostream&, const cpp::List <U>&);
};



template <class T>
class cpp::List
{
    private:
    Node<T>         *head;
    Node<T>         *tail;
    int list_length = 0;
    
    public:
    List(){}
    List(T value)
    {
        Node <T> *newNode   = new Node<T>(value);
        this->head          = newNode;
        this->tail          = newNode;
        this->tail->next    = NULL;
        this->list_length++;
    }

    void push(T);
    void pop();
    void insert(int,T);
    T    at(int);
    T    remove(int);
    List reverse();

    template<class U>
    friend std::ostream& ::operator<< (std::ostream&, const cpp::List<U>&);
    //:: for defining global namespace
};

template<class T> void cpp::List<T>::push(T value)
{
    Node <T> *new_node = new Node<T>(value);
    this->tail->next   = new_node;
    this->tail         = new_node;
    new_node->next     = NULL;
    if(!list_length) 
        this->head     = new_node;
    this->list_length++;
}

template<class T> void cpp::List<T>::pop()
{
    list_length--;
    Node <T> *current               = this->head;
    for(int i=1;i<list_length;i++) 
        current                     = current->next;
    this->tail                      = current;
    current->next                   = NULL;
}

template<class T> void cpp::List<T>::insert(int index, T value)
{
    
}

template<class T> T cpp::List<T>::at(int index)
{
    if(index < 0 || index >= this -> list_length)
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

template<class T>
std::ostream& operator<<(std::ostream &output,const cpp::List<T> &l)
{
    cpp::Node<T> *current       = l.head;
    output                      <<"[ ";
    while(current != NULL) 
    {
        output                  << current->data;
        if(current->next!=NULL)
            output              << ", ";
        current                 =  current->next;
    }
    output                      << " ]";
    return output;
}

#endif /* LIST_H */