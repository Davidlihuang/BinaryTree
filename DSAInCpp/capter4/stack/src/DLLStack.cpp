#include <iostream>
#include "DoubleLinkStack.h"

using namespace std;
void dllstackTest()
{
    DLLStack<int> mystack;
    for(int i =0; i< 5; i++)
    {
        mystack.push(i);
    }
    cout << mystack << endl;

    for(int i = 0; i< 2; i++)
    {
        cout << mystack.pop() << endl;
    }

    mystack.top() = 90;
    cout << mystack.top() << endl;
    
}