#include <iostream>
using namespace std;

class Array
{
    int length{};
    int *data;
    int size {};
    public:
    Array(int size)
    {
        this->length=0;
        this->size=size;
        this->data = new int[size] {0};
    }

    int at(int index)
    {
        if(index>length){cout<<"\n[-]Undefined\n";return -1;}
        return this->data[index];
    }

    void transfer()
    {
        int *temp_array = new int[size+1] {0};
        for(int i=0;i<size;i++) temp_array[i] = data[i];
        delete []data; //to free up space from heap memory
        data=temp_array;
        temp_array=NULL;
        this->size++;
    }

    void push(int element)
    {
        if(size==length){
            /*Need to create array with increased size and transfer elements from old array*/
            transfer();
        }
        this->data[this->length] = element;
        this->length++;
    }

    void pop()
    {
        if(length==0){cout<<"\n[-]Empty Array\n";}
        else this->length--;
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
        if(length<index+1){cout<<"\n[-]Undefined\n";}
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