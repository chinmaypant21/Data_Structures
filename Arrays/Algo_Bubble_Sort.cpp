#include <iostream>
using namespace std;

inline void print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])   swap(arr[j],arr[j+1]);
        }
    }
}

int main()
{
    int arr[] {1,4,5,0,2,1};
    int size=6;
    bubbleSort(arr,size);
    print(arr,size);

    return 0;
}