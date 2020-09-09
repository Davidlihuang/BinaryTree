#include <iostream>
#include "siglelinklist.h"

int main() {
    using namespace std;
    SingleList list;
    for(int i =0 ; i < 20; i++) {
        if( i < 10) {
            list.insertPost(i*i);
        } else {
            list.insertBefore(i*i);
        }  
    }
    cout <<"list: " <<list <<"\nList length: "<<list.listLength()<< endl;

    int val;
    for(int i = 0; i < 10; i++) {
        list.removeFirst(val);
    }
    cout <<"list: " <<list <<"\nList length: "<<list.listLength()<< endl;

    for(int i = 0; i < 10; i++) {
        list.removePost(val);
    }
    cout <<"list: " <<list <<"\nList length: "<<list.listLength()<< endl;

    cout << list.remove(1, val) << endl;
    cout << list.insert(1,val) << endl;
    cout <<"list: " <<list <<"\nList length: "<<list.listLength()<< endl;

    //copy list
    SingleList list2 = list; //调用复制构造函数；
    cout << "origin List: "<< list << endl;
    cout << "new List: " << list2 << endl;
    //assigment list
    SingleList newlist;
    for(int i =0 ; i < 20; i++) {
        if( i < 10) {
            newlist.insertPost(i*i);
        } else {
            newlist.insertBefore(i*i);
        }  
    }
    cout <<"newlist: " <<newlist <<"\nList length: "<<newlist.listLength()<< endl;
    SingleList list3;
    list3 = newlist;
    cout <<"list3: " <<list3 <<"\nList length: "<<list3.listLength()<< endl;
    
    cout<<"test ended"<<endl;
    return 0;
}