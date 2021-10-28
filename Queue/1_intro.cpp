#include <iostream>
using namespace std;
/** 
 * @brief In a Queue, the order of elements is FIFO, the element which is enqueued first, will go out first.
In class queue, we have taken two members front and end, which will store the index values.
Initially, both will point at -1 (which indicates that queue is not initiallzed yet).
When we enqueue an element, the end value will increase. When we pop an element, the front value
will increase. 
* We can see that the value of front is always one index before the first element index.
  Empty queue: when front=end, then the queue is empty,

* @brief Reason of maintaining two pointers front and end is to decrease Big O value of deletion.
  If we do not have a front pointer, so each time when an element is dequeued, we will have to
  shift all element to 1 index before to maintain order. But if we have a front index, we do not need
  to shift whole queue, we can shift the front index only to the index before top element
  Thus Big O reduces from O(n) to O(1).
*/
class Queue
{
    int front;
    int end;
    int size;
    int *queue_arr;

    public:
    Queue(int size)
    {
        this->size      = size;
        this->front     = -1;
        this->end       = -1;
        this->queue_arr = new int[size];
    }

    void enqueue(int value) // O(1)
    {
        if(this->end == this->size-1)
            cerr<<"\n[-] Queue is full\n";
        else
        {
            this->end++;
            queue_arr[end] = value;
        }
    }

    /**
     * @brief dequeues the top element present in queue
     * @return value of the first element in queue 
    */
    int dequeue() //O (1)
    {
        if(this->front == this->end)
        {
            cerr<<"\n[-] Queue is Empty\n";
            return -1;
        }
        else
        {
            this->front++;
            return queue_arr[front];
        }
    }

    void print() //O(n)
    {
        int current = front;
        while(current != end)
        {
            current++;
            cout<<queue_arr[current]<<" ";
        }
        cout<<endl;
    }

};

int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.print();

}