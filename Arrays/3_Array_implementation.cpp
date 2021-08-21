#include <iostream>
using namespace std;

class Array
{
    int length{};
    int *data;
    public:
    Array(int size)
    {
        this->length=0;
        this->data = new int[size] {0};
    }

    int at(int index)
    {
        return this->data[index];
    }

    void push(int element)
    {
        this->data[this->length] = element;
        this->length++;
    }

    void pop()
    {
        this->length--;
    }
    
    /*We have to make operator overloading function a friend of the class
    because it would be called without creating an object*/
    friend ostream & operator << (ostream &out_stream, const Array &arr)
    {
        for(int i=0;i<arr.length;i++)
        {
            out_stream<<arr.data[i]<<" ";
        }
        out_stream<<"\n";
         return out_stream;
    }

    void shift(int index)
    {
        for(int i=index; i<this->length-1;i++)
        {
            this->data[i] = this->data[i+1];
        }
    }

    void remove(int index)
    {
        this->shift(index);
        this->length--;
    }
};

int main()
{
    Array myArray(5);
    myArray.push(1);
    myArray.push(2);
    myArray.push(3);
    myArray.push(4);
    cout<<myArray; //after push

    myArray.pop();
    cout<<myArray;

    myArray.remove(1); //delete from index 2
    cout<<myArray;
    return 0;
}