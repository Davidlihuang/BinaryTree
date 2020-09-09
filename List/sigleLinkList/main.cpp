#include <iostream>
#include "siglelinklist.h"

int main() {
    using namespace std;
{
    /*
    SingleList list;
    for(int i =0 ; i < 20; i++) {
        if( i < 10) {
            list.insertPost(i*i);
        } else {
            list.insertBefore(i*i);
        }  
    }
    cout <<"list: " <<list <<"\nList length: "<<list.listLength()<< endl;
    
    // 插入删除test
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

    //调用复制构造函数test；
    SingleList list2 = list; 
    cout << "origin List: "<< list << endl;
    cout << "new List: " << list2 << endl;
*/
    //重新初始化list
    SingleList newlist;
    for(int i =0 ; i < 20; i++) {
        if( i < 10) {
            newlist.insertPost(i*i);
        } else {
            newlist.insertBefore(i*i);
        }  
    }
    cout <<"newlist: " <<newlist <<"\nList length: "<<newlist.listLength()<< endl;
    
    // 复制运算符test
    SingleList list3;
    list3 = newlist;
    cout <<"list3: " <<list3 <<"\nList length: "<<list3.listLength()<< endl;
    
    // 下标运算符test
    for(int i =0 ; i < 20; i++) { 
        cout<<"list3[i] = "<<list3[i] << endl;
    }
    list3[0] = 400;
    cout<< list3 << endl;
    cout<<"test ended"<<endl;
}

    return 0;
}