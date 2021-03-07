#include <iostream>
#include <string>
#include <vector>
#include "bubbleSort.h"


using namespace std;
int main(int argc, char* argv[])
{
    vector<int> vec = {5,41,2,355,12,12,45,1,2,3,5,4,8,6,3};
    int data[]{12,45,7,2,3,5,68,4,2,45,6,89,5,22,54};

    cout << "vec: ";
    printList(cout, vec);
    cout << endl;

    bubbleSort(vec, vec.size(), true); //increase 

    cout << "vec increase sort: ";
    printList(cout, vec);
    cout << endl;

    bubbleSort(vec, vec.size(), false); //decrease

    cout << "vec decreade sort: ";
    printList(cout, vec);
    cout << endl;

    vector<int> vec1{1,2,3,4,5,6,7,8,9,10};
    cout << "vec1：";
    printList(cout, vec1);
    cout << endl;
    bubbleSortOpt(vec1, vec1.size(), true);
    cout << "vec1 increase sort: ";
    printList(cout, vec1);
    cout << endl;

    cout << "vec1：";
    printList(cout, vec1);
    cout << endl;
    bubbleSortOpt(vec1, vec1.size(), false);
    cout << "vec1 decrease sort: ";
    printList(cout, vec1);
    cout << endl;
    return 0;
}