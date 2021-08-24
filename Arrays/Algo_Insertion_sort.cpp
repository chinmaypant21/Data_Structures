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

void insertionSort(int arr[],int size)
{

    for(int i=1;i<size;i++)
    {
        if(arr[i]<arr[i-1])
        {
            int temp=arr[i];
            for(int j=i-1;j>=0;j--)
            {
                arr[j+1]=arr[j];
                if(j==0 || temp>arr[j-1])
                {
                    arr[j]=temp;
                    break;
                }
            }
        }
    }
}

int main()
{
    int arr[] {6,5,4,3,0,1};
    int size=6;
    insertionSort(arr,size);
    print(arr,size);

    return 0;
}