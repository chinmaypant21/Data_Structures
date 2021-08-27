
#include <iostream>
using namespace std;

void bubbleSort(int[],int);

int linear_search(int array[],int size,int to_find)
{
    for(int i=0;i<size;i++)
    {
        if (array[i]==to_find) return i;
    }
    return -1;
}
/*
Time Complexity for linear search:
Best case O(1) when element found at first place
Worst case O(n) when element found at end
Avg case O(n)
*/


void print(int arr[],int size)
{
    for(int i=0;i<size;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int binary_search(int array[],int to_find,int end,int start=0)
{
    if (end>=start)
    {
        int middle=(start+end)/2;
        if (to_find>array[middle])
            return binary_search(array,to_find,end,middle+1);

        else if (to_find<array[middle])
            return binary_search(array,to_find,middle-1,start);

        else return middle;
    }
    else return -1;
}

int main()
{
    int size=13;
    int array[size] = {1, 4, 46, 37, 8, 54, 0, 3, 43, 5, 6, 7, 52};
    int index = linear_search(array,size,8);
    bubbleSort(array,size);
    cout<<"\nLINEAR SEARCH:";
    if(index!=-1) cout<<"Number found at index "<<index;
    else cout<<"Number not present in array";

    cout<<"\nSorted Array: ";print(array,size);
    cout<<"\nBINARY SEARCH: ";
    index = binary_search(array,8,size-1);
    if(index!=-1) cout<<"Number found at index "<<index;
    else cout<<"Number not present in array";

}

void bubbleSort(int arr[],int size)/*Only required for Sorting Array to perform Binary Search*/
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])   swap(arr[j],arr[j+1]);
        }
    }
}