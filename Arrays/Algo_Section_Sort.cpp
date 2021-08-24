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

void selectionSort(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        int temp_index = i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[temp_index]) temp_index=j;
        }
     
        swap(arr[i],arr[temp_index]);
    }
}

int main()
{
    int arr[] {1,4,5,0,2,3};
    int size=6;
    selectionSort(arr,size);
    print(arr,size);

    return 0;
}