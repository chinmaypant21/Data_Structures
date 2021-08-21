#include <iostream>
using namespace std;

void print(int array[],int end_index)
{
    for(int i=0; i<=end_index;i++) cout<<array[i]<<" ";
}

int main()
{
    int size=10;
    int end_index=6;
    int int_array[size] {1,2,3,4,5,6,7};

    //Insert at End
    end_index++;
    int_array[end_index] = 8;
    cout<<"\nInsert at End\n";
    print(int_array,end_index);

    //Delete from End
    end_index--;
    cout<<"\nDelete from end\n";
    print(int_array,end_index);

    //Inserting 9 at beginning
    for(int i=end_index;i>=0;i--)
    {
        int_array[i+1] = int_array[i];
    }
    int_array[0] = 9;
    cout<<"\nInsert at Beginning\n";
    print(int_array,end_index);


    //Deleting element from index 3
    for(int i=3;i<end_index;i++)
    {
        int_array[i]= int_array[i+1];
    }
    end_index--;
    cout<<"\nDelete\n";
    print(int_array,end_index);


    //Remove 3 elements starting from index 2
    int starting_index=2;
    int num_del_elements=3;
    for(int i=starting_index; i<end_index;i++)
        int_array[i] = int_array[i+num_del_elements];
    end_index-=num_del_elements;
    cout<<"\nDeleting from Between the array\n";
    print(int_array,end_index);

    return 0;
}