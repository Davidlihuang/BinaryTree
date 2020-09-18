#include <iostream>
#include "sequnstack.h"
#include "liststack.h"

using namespace std;
int main() {
    ListStack<int> lstack;
    for (int i=0;i<3;i++) {
        lstack.push(i+1);
    }
    cout <<"---------stackList--------\n初始化栈："<<lstack << endl;

    //copy Constructor
    ListStack<int> lstack1(lstack);
    cout <<"复制构造函数初始化栈："<< lstack1 << endl;

    //assigned 
    ListStack<int> lstack2;
    lstack2 = lstack1;
    cout << "赋值：" << lstack2 << endl;
    
    //pop all element
    int val = 0;
    while(lstack.size()) {
        val = lstack.pop();
        cout <<"pop:" <<val << "\t";
    }
    cout << endl;
    
    cout << lstack << endl;

    //sequenList
    cout <<"---------sequenList--------\n初始化栈："<<lstack << endl;
    SequenStack<int> sstack(10);
    for(int i =0; i<10; i++) {
        sstack.push(i+1);
    }
    cout <<"sequen stack size: "<<sstack.size()<< " elemet: "<<sstack << endl;
    for(int i =0; i<11; i++) {
        sstack.pop();
        cout <<"sequen stack size: "<<sstack.size()<< " elemet: "<<sstack << endl;   
    }
    cout << "test ended!" <<endl;
    return 0;
}