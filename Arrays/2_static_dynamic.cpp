/*
Python has lists which are used in place of arrays, and are dynamic in nature
JavaScript array are dynamic in nature
*/

//In C++ we can make arrays static and dynamic both.
#include <iostream>
using namespace std;

int main()
{
    int static_array[5] {1,2,3,4,5};
    for(int i:static_array) cout<<i<<" ";
    //This array has a size of 5, so no more elements can be appended


    int *dynamic_array;
    dynamic_array = new int[5] {0};
    //Initializing a dynamic array of size 3 with 0;

    for (int x = 0; x < 5; x++) 
		dynamic_array[x] = x+1;

    cout<<"\nEntered array:\n";
    for (int x = 0; x < 5; x++) {
		cout << dynamic_array[x] << " ";
	}

    // dynamic_array[5] = 6;
    // dynamic_array[6] = 7;

    //  cout<<"\nEntered array:\n";
    // for (int x = 0; x <=6; x++) {
	// 	cout << dynamic_array[x] << " ";
	// }


}