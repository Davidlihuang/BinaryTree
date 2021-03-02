#include <iostream>
#include "intSLList.h"

using namespace std;
int main()
{
    IntSLList myList;

    cout << "add to head!" << endl;
    for (int i = 0; i < 5; i++)
    {

        myList.addToHead(i);
    }
    cout << "add to tail!" << endl;
    for (int i = 0; i < 5; i++)
    {

        myList.addToTail(i);
    }
    cout << myList<<endl;

   cout << "delete from head!" << endl;
   for(int i=0; i< 7;i++) 
   {
       myList.deleteFromHead();
   }
   cout<< myList<< endl;

    int e;
    cout << "delete Node(e): ";
    cin >>e;
    myList.deleteNode(e);
    cout << myList<<endl;
    return 0;
}