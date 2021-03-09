#include <iostream>
#include "cicleQueue.h"

using namespace std;
int main()
{
    CircleQueue<int , 5> que;
    cout <<que.isEmpty()<< endl;
    cout <<"capacity :"<< que.capacity() << endl;
    cout <<"size: " <<que.queueSize() << endl;
    for(int i=0; i< que.capacity(); i++)
    {
        que.push_back(i+1);
    }
    cout <<"size: "<< que.queueSize()<< endl;
    que.pop_front();
    que.pop_front();
    cout <<"size: "<< que.queueSize()<< endl;
    que.push_back(12);
    cout <<"size: "<< que.queueSize()<< endl;
    que.push_back(23);
    cout <<"size: "<< que.queueSize()<< endl;

    //会溢出
    // cout << "is full: " << que.isFull() << endl;
    // que.push_back(23);
    // cout <<"size: "<< que.queueSize()<< endl;
    
    //获取头尾元素
    cout << "get front: " << que.front() << endl;
    cout << "get back: " << que.back() << endl;
    cout << "change fron(20): " ;
    que.front() = 20;
    cout << que.front()<< endl;

    cout <<"change back(21):";
    que.back() = 21;
    cout << que.back()<<endl;

    for(int i =0; i< 4; i++)
    {
        cout << "pop: "<< que.pop_front()<< endl;
    }
    cout << "isEmpty: " << que.isEmpty() << endl;

    return 0;
}
