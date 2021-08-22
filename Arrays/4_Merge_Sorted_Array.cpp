#include <iostream>
using namespace std;

int main()
{
    int size1{5},size2{5};
    int array1[size1] {1,2,3,4,5};
    int array2[size2] {4,6,7,8,9};
    int merged_array[size1+size2] {0};

    int first_array_iterator {};
    int second_array_iterator {};
    int i=0;



    while(first_array_iterator<size1 and second_array_iterator<size2)
    {
        if(array1[first_array_iterator]==array2[second_array_iterator])
        {
            merged_array[i++]=array1[first_array_iterator++];
            // merged_array[i++]=array2[second_array_iterator++];  /*Using this statement will cause duplicate elements*/
            second_array_iterator++;
        }

        else if(array1[first_array_iterator]<array2[second_array_iterator])
        {
            merged_array[i++]=array1[first_array_iterator++];
        }

        else
        {
            merged_array[i++] = array2[second_array_iterator++];
        }
    }

    //when elements of any of those array are completely used, then we can add elements of second array directly
    if(first_array_iterator==size1)
    {
        while(second_array_iterator<size2)
        {
            merged_array[i++]=array2[second_array_iterator++];
        }
    }

    else
    {
        while(first_array_iterator<size1)
        {
            merged_array[i++]=array2[second_array_iterator++];
        }
    }

    for(int j=0;j<i;j++)
    {
        cout<<merged_array[j]<<" ";
    }
}