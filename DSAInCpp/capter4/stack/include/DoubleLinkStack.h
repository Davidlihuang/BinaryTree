#ifndef DOUBLELINKSTACK_H_
#define DOUBLELINKSTACK_H_
#include <iostream>
using namespace std;

template <class NT>
class DLLstackNode
{
public:
    DLLstackNode() : pre(nullptr), next(nullptr) {}
    DLLstackNode(NT element, DLLstackNode<NT> *p = nullptr, DLLstackNode<NT> *n = nullptr) : data(element), pre(p), next(n) {}

    NT data;
    DLLstackNode<NT> *pre;
    DLLstackNode<NT> *next;
};

template <class T>
class DLLStack
{
private:
    DLLstackNode<T> *topPointer;

public:
    DLLStack() : topPointer(nullptr) {}

    bool isEmpty() const { return topPointer == nullptr; }
    void push(const T &data)
    {
        if (isEmpty())
        {
            topPointer = new DLLstackNode<T>(data);
        }
        else
        {
            topPointer->pre = new DLLstackNode<T>(data, nullptr, topPointer);
            topPointer = topPointer->pre;
        }
    }

    T pop()
    {
        T data;
        if (isEmpty())
        {
            throw "pop a empty stack...!";
        }
        else
        {
            DLLstackNode<T> *tempNode = topPointer;
            data = topPointer->data;
            topPointer = topPointer->next;
            delete tempNode;
            topPointer->pre = nullptr;
        }
        return data;
    }
    T &top()
    {
        if (!isEmpty())
        {
            return topPointer->data;
        }
        else
        {
            throw "get top from an empty stack!";
        }
    }
    void print(std::ostream &os)
    {
        DLLstackNode<T> *tempNode = topPointer;
        while (tempNode)
        {
            os << tempNode->data << " ";
            tempNode = tempNode->next;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, DLLStack<T> &dlStack)
    {
        dlStack.print(os);
        return os;
    }

    ~DLLStack()
    {
        DLLstackNode<T> *tempNode = nullptr;
        while (!isEmpty())
        {
            tempNode = topPointer;
            topPointer = topPointer->next;
            delete tempNode;
        }
    }
};

void dllstackTest();
#endif