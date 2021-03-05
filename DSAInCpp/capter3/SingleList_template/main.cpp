#include <iostream>
#include "singlelist_tem.h"
#include <string>

using namespace std;
int main(int argc, char* argv[])
{

    SingleList<int> myList;
    myList.addToHead(1);
    cout << "length: "<<myList.size()<<" content: "<<myList << endl;
    myList.addToHead(2);
    cout << "length: "<<myList.size()<<" content: "<<myList << endl;
    myList.addToTail(3);
    cout << "length: "<<myList.size()<<" content: "<<myList << endl;
    myList.addToTail(4);
    cout << "length: "<<myList.size()<<" content: "<<myList << endl;

    myList.insertElement(7, 1);
    cout << "length: "<<myList.size()<<" content: "<<myList << endl;
    myList.insertElement(8, 2);
    cout << "length: "<<myList.size()<<" content: "<<myList << endl;
    myList.insertElement(9, 3);
    cout << "length: "<<myList.size()<<" content: "<<myList << endl;

    myList.deleteFromHead();
    cout << "length: "<<myList.size()<<" content: "<<myList << endl;
    myList.deleteFromHead();
    cout << "length: "<<myList.size()<<" content: "<<myList << endl;
    myList.deleteFromTail();
    cout << "length: "<<myList.size()<<" content: "<<myList << endl;
    myList.deleteFromTail();
    cout << "length: "<<myList.size()<<" content: "<<myList << endl;
    
    myList.deleteElement(1);
    cout << "length: "<<myList.size()<<" content: "<<myList << endl;
    myList.deletePositonElement(2);
    cout << "length: "<<myList.size()<<" content: "<<myList << endl;

    SingleList<string> str(10, "love");
    //SingleList<string> str1(5, "I");
    //SingleList<string> str2(15, "you");

    cout <<"拷贝构造函数："<< endl;
    SingleList<string> str3(str);
    SingleList<string> str4 = str3;
    cout << "str1: "<<str << endl;
    cout <<"str3: "<< str3<< endl;
    cout << "str4: " << str4 << endl;

    cout << "拷贝赋值函数："<< endl;
    SingleList<string> str1(3, "I");
    SingleList<string> str2(6,"you");
    SingleList<string> str0;
    str = str2;
    str = str1;
    cout << "str: " <<str << endl;
   // str = str1;




    
    

    return 0;
}