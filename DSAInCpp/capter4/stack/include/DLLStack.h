#ifndef DLLSTACK_H_
#define DLLSTACK_H_
#include <iostream>
using namespace std;

template<class NT>
class stackNode
{
public:
    stackNode():pre(nullptr), next(nullptr) {}
    stackNode(NT element, stackNode<NT>*p = nullptr, stackNode<NT>* n = nullptr):   data(element), pre(p), next(n) { }
    
    NT data;
    stackNode<NT>* pre;
    stackNode<NT>* next;
};

template<class T>
class DLLStack
{
public:
    DLLStack(){}
    ~DLLStack(){}
private:
    stackNode<T>* topPointer;
};
#endif