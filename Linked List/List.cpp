#include <iostream>
#include "List.h"
using namespace std;
using namespace cpp;

int main()
{
    // int ar[] = {4,5,6};
    // List<int> l(ar,3);
    List<int> l;
    l.push(1);
    l.push(2);
    l.push(3);
    cout<<l<<endl;
    cout<<"--End--"<<endl;
}