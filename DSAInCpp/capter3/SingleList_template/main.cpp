#include <iostream>
#include "singlelist_tem.h"

using namespace std;
int main(int argc, char* argv[])
{
    SingleList<int> myList;
    myList.addToHead(1);
    myList.addToHead(2);
    myList.addToTail(3);
    myList.addToTail(4);

    myList.insertElement(7, 1);
    myList.insertElement(8, 2);
    myList.insertElement(9, 3);

    cout << myList<<endl;
    return 0;
}