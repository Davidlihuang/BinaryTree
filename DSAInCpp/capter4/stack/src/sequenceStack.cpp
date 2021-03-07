#include <iostream>
#include "sequenceStack.h"

void sequenStackTest()
{
    using namespace std;
    SequenceStack<int, 10> myStack;
    for(int i=0; i< 10; i++)
    {
        myStack.push(i+1);
    }
    cout << myStack << endl;
    cout << myStack.isFull() << endl;
    myStack.push(10);
    cout <<  myStack << endl;
    myStack.top() =  23;

    cout << "pop element: "; 
    for(int i =0 ; i< 5; i++)
    {
        cout << myStack.pop()<< " ";
    }
    cout << endl;
}

void vecSequenStackTest()
{
    using namespace std;
    VecSequenceStack<int , 10> myStack;
    for(int i=0; i< 20; i++)
    {
        myStack.push(i+2);
    }
    cout <<"vec sequence stack: ";
    cout <<  myStack << endl;

    cout <<"push full:";
    cout << myStack.isFull() << endl;

    myStack.push(20);
    cout <<myStack << endl;

    cout <<"vec stack top: " << myStack.top() <<endl;
    cout << "vec stack change top(32):" ;
    myStack.top() = 32;
    cout << myStack.top()<<endl;
    cout << myStack << endl;

}