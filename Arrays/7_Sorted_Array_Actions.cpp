#include <iostream>
using namespace std;

void insert_sorted(int arr[],int &size,int to_insert)
{
    for(int i=size;i>=0;i--)
    {
        if(to_insert>arr[i-1] || i==0)
        {
            arr[i]=to_insert;
            size++;
            return;
        }
        arr[i]=arr[i-1];
    }
}

bool checkSorted(int arr[],int size)
{
    for(int i=1;i<size;i++)
    {
        if(arr[i]<arr[i-1]) return false;
    }

    return true;
}

void print(int arr[],int size)
{
    for(int i=0;i<size;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int length = 7;
    int size=10;
    int to_insert = 5;
    int sorted_array[size] = {1,3,6,11,13,14,18};
    insert_sorted(sorted_array,length,to_insert);
    print(sorted_array,length);
    // cout<<checkSorted(sorted_array,length)<<endl;
}