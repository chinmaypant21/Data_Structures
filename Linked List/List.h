#ifndef LIST_H //Include Guard
#define LIST_H

#include <iostream>
// using namespace std;

namespace cpp{
    template <class> class List;
    template <class> class Node;
}

template<class T> 
std::ostream& operator << (std::ostream&, const cpp::List <T>&);//prototype

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

    template<class U> 
    friend std::ostream& ::operator<< (std::ostream&, const cpp::List <U>&);
};



template <class T>
class cpp::List
{
    private:
    Node<T>  *head;
    Node<T>  *tail;
    int list_length = 0;
    
    public:
    List(){}
    List (const List &l) //deep copy
    {
        cpp::Node<T> *current = l.head;
        for(int i=0; i<l.list_length;i++)
        {
            this->push(current->data);
            current = current->next;
        }
    }

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
    friend std::ostream& ::operator<< (std::ostream&, const List<U>&);
    //:: for defining global namespace
    List operator + (const cpp::List<T>&);
    void operator += (const cpp::List<T>&);
};

template<class T>
void cpp::List<T>::push(T value)
{
    Node <T> *new_node = new Node<T>(value);
    if(!list_length)
    {
        this->head       = new_node;
        this->tail       = new_node;
    }  
    else
    {
        this->tail->next = new_node;
        this->tail       = new_node;
    }
    new_node->next       = NULL;

    this->list_length++;
}

template<class T>
void cpp::List<T>::pop()
{
    if(list_length==0)
    {
        /*Exception Handling*/
        return;
    }
    if(list_length==1)
    {
        this->head  = NULL;
        this->tail  = NULL;
    }
    else
    {
        Node <T> *current = this->head;
        for(int i=1;i<list_length;i++) 
            current       = current->next;
        this->tail        = current;
        current->next     = NULL;
    }
    
    list_length--;
}

template<class T>
void cpp::List<T>::insert(int index, T value)
{
    if(index > this->list_length || index<0)
    {
        /*Exception Handling*/
        return;
    }

    Node<T> *newNode        = new Node<T>(value);
    Node<T> *index_pointer  = this->head;
    if(index==this->list_length) 
        this->tail = newNode;

    this->list_length++;
    if(index==0) 
    {
        newNode->next = this->head;
        this->head    = newNode;
        this->tail    = newNode;
        return;
    }

    for(int i=0; i<index-1; i++)
    {
        index_pointer = index_pointer->next;
    }
    newNode->next       = index_pointer->next;
    index_pointer->next = newNode;
}

template<class T>
T cpp::List<T>::at(int index)
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

template<class T>
T cpp::List<T>::remove(int index)
{
    
}

template<class T> 
cpp::List<T> cpp::List<T>::reverse()
{
    List<T> reverse_list;
    /* ---- */
    return reverse_list;
}

template<class T>
std::ostream& operator << (std::ostream &output,const cpp::List<T> &l)
{
    cpp::Node<T> *current = l.head;
    output << "[ ";
    while (current != NULL)
    {
        output << current->data;
        if (current->next != NULL)
            output << ", ";
        current = current->next;
    }
    output << " ]";
    return output;
}

template<class T>
cpp::List<T> cpp::List<T>::operator + (const cpp::List<T>& l)
{
    cpp::List<T> _result_list;
    cpp::Node<T> *current = this->head;

    for(int i=0;i<this->list_length;i++)
    {
        _result_list.push(current->data);
        current = current->next;
    }

    current = l.head;
    for(int i=0;i<l.list_length;i++)
    {
        _result_list.push(current->data);
        current = current->next;
    }
    return _result_list;
}

template<class T>
void cpp::List<T>::operator += (const cpp::List<T>& l)
{
    cpp::Node<T> *current = l.head;
    for(int i=0;i<l.list_length;i++)
    {
        this->push(current->data);
        current = current->next;
    }
}
#endif /* LIST_H */
