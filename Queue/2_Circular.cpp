#include <iostream>
using namespace std;

class Queue
{
    int front;
    int end;
    int size;
    int *queue_arr;

    /**
     * @brief it gives the index of the next position of the member in the circular queue according
     * to size of queue and current position of that member variable.
     * @param val current value
     * @return next index value.
    */
    inline int nextIndex(int val)
    {
        return ( (val + 1) % this->size );
    }

    public:
    Queue(int size)
    {
        this->size      = size;
        this->front     = 0;
        this->end       = 0;
        this->queue_arr = new int[size];
    }

    void enqueue(int value) // 
    {
       if(this->nextIndex(end) == this->front)
       {
           cerr<<"\n[-]Queue is Full!\n";
       }

       else
       {
           this->end = this->nextIndex(end);
           queue_arr[end] = value;
       }
    }

    /**
     * @brief dequeues the top element present in queue
     * @return value of the first element in queue 
    */
    int dequeue() //
    {
        if(this->end == this->front)
        {
            cerr<<"\n[-]Queue is Empty!\n";
            return -1;
        }
        else
        {
            this->front = this->nextIndex(front);
            int temp = queue_arr[front];
            queue_arr[front] = 0;
            return temp;
        }
    }

    void print() //O(n)
    {
        int current=front;
        while(current!=end)
        {
            current = this->nextIndex(current);
            cout<<queue_arr[current]<<" ";
        }
        cout<<endl;
    }

    //For Degugging displaying queue value containter array
    void disp()
    {
        for(int i=0;i<size;i++)
        {
            cout<<queue_arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main()
{
    Queue q(7);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.dequeue();
    q.dequeue(); 
    q.enqueue(7);
    q.enqueue(8);
    q.print();

    cout<<"Array: \n";
    q.disp();

}