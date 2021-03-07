#include <iostream>
#include "singleListStack.h"

using namespace std;
void singleStackTest()
{
    SingleListStack<int> myStack;
    for(int i =0; i< 5; i++)
    {
        myStack.push(i+1);
    }
    while( !myStack.isEmpty())
    {
        myStack.pop();
    }
    
    cout << myStack<<endl;
}