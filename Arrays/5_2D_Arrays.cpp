#include <iostream>
using namespace std;


int main()
{
    int twoD_arr[3][2] = { {1,2}, {2,3}, {5,6} };
    /* This will create a 2D array in Stack memory */


    int *arr_2D[3] {};
    for(int i=0;i<3;i++){arr_2D[i] = new int[2];}
    //This will create array partially in stack mem and partially in heap memory

    // assigning values
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            arr_2D[i][j]=i+j;
        }
    }


    int **heap_2DArray = new int*[3];
    //heap2DArray is a pointer to pointer by this way we can create a 2D array completely in heap memory
    for(int i=0;i<3;i++){heap_2DArray[i]=new int[2];}

    //assigning values
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            heap_2DArray[i][j]=i+j;
        }
    }


    //Display 2D array
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<twoD_arr[i][j]<<" ";
        }
        cout<<endl;
    }   
    cout<<endl;


    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<arr_2D[i][j]<<" ";
        }
        cout<<endl;  
    }    
    cout<<endl;


    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<heap_2DArray[i][j]<<" ";
        }
        cout<<endl;
    }    
}