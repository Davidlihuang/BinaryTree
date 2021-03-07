#ifndef DLLSTACK_H_
#define DLLSTACK_H_
#include <iostream>
#include <vector>

template <typename T, int size = 100>
class SequenceStack
{
public:
    SequenceStack()
    {
        topPoint = -1;
        data = new T[size];
    }
    ~SequenceStack()
    {
        delete[] data;
    }
    bool isEmpty() const { return topPoint == -1; }
    bool isFull() const { return topPoint == (size - 1); }
    T pop();
    void push(const T &el);
    T &top();
    void print(std::ostream& os);
    friend std::ostream& operator<< (std::ostream& os,  SequenceStack<T, size>& myStack)
    {
        myStack.print(os);
        return os;
    }
private:
    T *data;
    int topPoint;
};


template <typename T, int capacity = 100>
class VecSequenceStack
{
public:
    VecSequenceStack()
    {
        data.reserve(capacity);
    }
    ~VecSequenceStack()
    {
        data.clear();
    }
    bool isEmpty() const {return data.empty();}
    bool isFull() const { return data.size() == capacity; }
    T& top(){
        return data.back();
    }
    T pop()
    {
        T el = data.back();
        data.pop_back();
        return el;
    }
    void push(const T& element)
    {
        if( false == isFull())
            data.push_back(element);
    }
    void print(std::ostream& os)
    {
        for(int i=0; i< data.size(); i++)
        {
            os << data[i] << " ";
        }
    }
    friend std::ostream& operator<<(std::ostream& os, VecSequenceStack<T, capacity>& myStack)
    {
        myStack.print(os);
        return os;
    }
private:
    std::vector<T> data;
};



/************************************************************************************************
 * * 数组保存栈数据
 * ***********************************************************************************************/
//压栈
template<typename T, int size>
void SequenceStack<T, size>::push(const T& element)
{
    if( false == isFull()) 
    {
        data[++topPoint] = element;
    }
    else
    {
        return ;
    }
}

//弹出栈顶
template<typename T, int size>
T SequenceStack<T, size>::pop()
{
    T temp;
    if( false == isEmpty())
    {
        temp = data[topPoint];
        topPoint--;
    }
    else{
        throw "try to pop an element from a empty stack";
    }
    return temp;
}

//返回栈顶元素
template<typename T,  int size>
T& SequenceStack<T, size>::top()
{
    if( false == isEmpty() )
    {
        return data[topPoint];
    }
    else{
        throw "an empty stack";
    }
}

// 打印元素
template<typename T, int size>
void SequenceStack<T, size>::print(std::ostream& os)
{
    for(int i=0; i<= topPoint; i++)
    {
        os<< data[i] <<" ";
    }
}

/************************************************************************************************************************
 *测试历程
 * **********************************************************************************************************************/ 
void sequenStackTest();
void vecSequenStackTest();
#endif