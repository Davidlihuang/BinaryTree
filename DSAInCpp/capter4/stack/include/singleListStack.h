#ifndef   SINGLELISTSTACK_H_
#define  SINGLELISTSTACK_H_
#include <iostream>

//节点
template<class NT>
class stackNode
{
public:
    stackNode():next(nullptr){}
    stackNode(NT el, stackNode<NT>* n = nullptr): data(el), next(n){}
    NT data;
    stackNode<NT>* next;
};


//栈
template<class T>
class SingleListStack
{
public:
    SingleListStack():size(0), topPointer(nullptr){}
    ~SingleListStack()
    {
        while(topPointer != nullptr)
        {
            delete topPointer;
            topPointer = topPointer->next;  
        }
    }
    bool isEmpty()const { return topPointer == nullptr; }
    T& top()
    {
        if( !isEmpty())
            return topPointer->data;
        else 
            throw "empty Stack!";
    }
    T pop()
    {
        T tempData;
        if( nullptr != topPointer)
        {
            --size;
            tempData = topPointer->data;
            topPointer =  topPointer->next;
        }
        else{
            throw "empty stack!";
        }
        return tempData;
    }
    void push(const T& el)
    {
        topPointer = new stackNode<T>(el, topPointer);  
        ++size;
    }
    void print(std::ostream& os)
    {
        stackNode<T>* temp =  topPointer;
        while(temp != nullptr)
        {
            os << temp->data <<" ";
            temp = temp->next;
        }
    }
    friend std::ostream& operator<< (std::ostream& os, SingleListStack<T>& myStack)
    {
        myStack.print(os);
        return os;
    }
private:
    stackNode<T>* topPointer;
    int size;
};

void singleStackTest();
#endif