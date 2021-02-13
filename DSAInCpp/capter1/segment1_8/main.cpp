#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "vec.h"

using namespace std;
template<class T>
void printVector(char* s, const vector<T>& v)
{
    cout << s << "= (";
    if (v.size() == 0) {
        cout << ")\n";
        return ;
    }
    typename vector<T>::const_iterator i = v.begin();
    for( ; i != v.end()-1; i++) {
        cout << *i << ' '; 
    }
    cout << *i << "\n";
}

bool f1(int n ) {
    return n < 4;
}

int main()
{
    //向量的初始化方式：
    //* 1. vector<T> v1
    //* 2. vector<T> v1(3, 7)   {7,7,7}
    //* 3. vector<T> v1(v2.iterator1,  v2.iterator2) [v2.iterator1, v2.iterator2)用v2之间的元素用来初始化向量v1
    //* 4. vector<T> v1(3) {0, 0, 0}
    //* 5. vextor<T> v1(v2) 使用另一个向量初始化v1
    int a[] = {1, 2, 3, 4, 5};
    vector<int> v1;
    cout <<"v1 size = " << v1.size() << " v1.capacity= " << v1.capacity()<< endl;
    printVector("v1", v1);
    for(int i = 1; i <= 5; i++) {
        v1.push_back(i);
    }
    cout <<"v1 size = " << v1.size() << " v1.capacity= " << v1.capacity()<< endl;
    vector<int> v2(3, 7);
    cout <<"v2 size = " << v2.size() << " v2.capacity= " << v2.capacity()<< endl;
    vector<int>::iterator iter1  = v1.begin()+1;
    vector<int> v3(iter1, iter1+1);
    cout <<"v3 size = " << v3.size() << " v3.capacity= " << v3.capacity()<< endl;
    vector<int> v4(v1);
    cout <<"v4 size = " << v4.size() << " v4.capacity= " << v4.capacity()<< endl;
    vector<int> v5(5);
    cout <<"v5 size = " << v5.size() << " v5.capacity= " << v5.capacity()<< endl;
    v5[1] = v5.at(3) = 9;
    
    //向量的空间重新分配方式
    //* v.reserve(n): 为空间小于n的向量，该函数为向量预留保存n个元素的空间
    //* v.resize(size_type n, const T& el = T()):  使向量保存n个元素， 方法是： 通过元素el 填充n-size()个位置， 或者丢弃向量末尾溢出的size()-n  个位置
    cout <<"befor reserve:  v3 size = " << v3.size() << " v3.capacity= " << v3.capacity()<< endl;
    v3.reserve(10);
    cout <<"After reserve:  v3 size = " << v3.size() << " v3.capacity= " << v3.capacity()<< endl;

    v4.resize(7);
    v4.resize(3);
    v4.clear();

    //向量的插入操作
    v4.insert(v4.end(), v3[0]);
    v4.insert(v4.end(), v3.at(0));
    v4.insert(v4.end(), 2, 4);
    v4.insert(v4.end(), v1.begin()+1, v1.end()-1);

    //向量元素擦除操作
    v4.erase(v4.end() - 2); 
    v4.erase(v4.begin(), v4.begin()+3);
    
    //assign(n, el) 删除向量的所有元素， 然后讲n个el的副本插入向量
    v4.assign(3, 8);
    v4.assign(a, a+3);

  //反向迭代器
    vector<int>::reverse_iterator riter =  v4.rbegin();
    for( ; riter != v4.rend(); riter++) {
        cout << *riter << " ";
    }
    cout << endl;

    // 算法
    v5[0] = 3;
    replace_if(v5.begin(), v5.end(), f1, 7);   //在整个向量中，如果满足条件f1， 则将对应元素替换为7
    v5[0] = 3; v5[2] = v5[4] = 0;
    replace(v5.begin(), v5.end() ,0, 7);

    sort(v5.begin(), v5.end());
    sort(v5.begin(), v5.end(), greater<int> ());  
    v5.front() = 2;
     
    return 0;
}