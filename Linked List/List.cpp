#include <iostream>
#include "List.h"
using namespace std;
using namespace cpp;

int main()
{
    List<int> l;
    l.push(1);
    l.push(2);
    l.push(3);
    cout<<l<<endl;
    cout<<l.at(2)<<endl;
    cout<<"--End--"<<endl;
}