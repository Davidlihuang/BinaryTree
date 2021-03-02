#ifndef INTSLLIST_H_ 
#define INTSLLIST_H_
#include <iostream>
//节点
class IntSLLNode{
public:
    IntSLLNode():next(nullptr){}
    IntSLLNode(int e, IntSLLNode* ptr = nullptr):info(e), next(ptr){}
    int info;
    IntSLLNode* next;
};

//链表
class IntSLList{
public:
    IntSLList():head(nullptr), tail(nullptr){}
    ~IntSLList();

    int isEmpty() { return head == nullptr; }
    void addToHead(int);
    void addToTail(int);
    int deleteFromHead();
    int deleteFromTail();
    void deleteNode(int);
    bool isInList(int) const;
    void print(std::ostream&);
    friend std::ostream& operator<<(std::ostream&,  IntSLList&);

private:
    IntSLLNode* head;
    IntSLLNode* tail;
    
};



#endif