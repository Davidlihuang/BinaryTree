#ifndef DOUBLELINKLIST_H_
#define DOUBLELINKLIST_H_
#include <iostream>
using namespace std;

template<class T>
class DoubleList {
private:
    struct ListNode;
    struct ListNode
    {
        T data;
        ListNode* next;
        ListNode* pre;
        ListNode():next(nullptr), pre(nullptr) { }
        ListNode(T val): data(val), next(nullptr), pre(nullptr) { }
        ListNode* insertBeforNode(const T& val);
        ListNode* insertAfterNode(const T& val);
    };
public:
    enum Status {Error = 0, OK = 1, Warning = 2};
    DoubleList();
    DoubleList(const DoubleList<T>& dlist);
    ~DoubleList();
    Status insert(int i, T val);
    Status insertFromHead(T val);
    Status insertFromTail(T val);
    Status remove(T& val);
    Status removeFromHead(T& val);
    Status removeFromTail(T& val);   
    ListNode* getFirstElement();
    ListNode* getLastElement();
    ListNode* getElement(int i);
    ListNode* locateData(T& val);
    Status cycledList();
    bool isCycleList();
    Status clearList();
    DoubleList<T>& operator=(const DoubleList<T>& dlist); 
    ListNode& operator[](int i);
    const ListNode& operator[](int i) const;
    template <class U>
    friend ostream& operator<<(ostream& os, const DoubleList<U> list);
    
private:
    ListNode* head;
    ListNode* tail;
    int length;
    
};

template<class T>
typename DoubleList<T>::ListNode* DoubleList<T>::ListNode::insertBeforNode(const  T& val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = this;
    newNode->pre = this->pre;
    this->pre->next = newNode;
    this->pre = newNode;
    length++;
    return newNode;
}
template<class T>
typename DoubleList<T>::ListNode* DoubleList<T>::ListNode::insertAfterNode(const T& val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = this->next;
    newNode->pre = this;
    this->next->pre = newNode;
    this->next = newNode;
    length++;
    return newNode;
}

template<class T>
DoubleList<T>::DoubleList() {
    head = new ListNode;
    tail = new ListNode;
    head->next = tail->pre;
    tail->pre = head;
}
template<class T>
DoubleList<T>::DoubleList(const DoubleList<T>& dlist) {

}
template<class T>
DoubleList<T>::~DoubleList() {
    clearList();
    if(length == 0) {
        delete head;
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
}
template<class T>
typename DoubleList<T>::Status DoubleList<T>::insert(int i, T val) {
    Status st = OK;
    ListNode* p = head;
    ListNode* newNode = nullptr;
    int j = 0 ;
    while (p ||j < i-1) {
        p = p->next;
        j++;
    }
    if (!p || j > i) {
        st = Error;
        return st;
    }
    newNode = new ListNode(val);
    p->insertAfterNode(newNode);
    length++;
    return OK;
}
template<class T>
typename DoubleList<T>::Status DoubleList<T>::insertFromHead(T val) {
    Status st = OK;
    ListNode* pcur = nullptr;
    pcur = head.insertAfterNode(val);
    return st;
}
template<class T>
typename DoubleList<T>::Status DoubleList<T>::insertFromTail(T val) {
    Status st = OK;
    ListNode* pcur = nullptr;
    pcur = tail.insertBeforeNode(val);
    if (pcur ==  nullptr) {
        st = Error;
    }
    return st;
}
template<class T>
typename DoubleList<T>::Status DoubleList<T>::remove(T& val) {

}
template<class T>
typename DoubleList<T>::Status DoubleList<T>::removeFromHead(T& val) {

}
template<class T>
typename DoubleList<T>::Status DoubleList<T>::removeFromTail(T& val) {

}  
template<class T>
typename DoubleList<T>::ListNode* DoubleList<T>::getFirstElement() {

}
template<class T>
typename DoubleList<T>::ListNode* DoubleList<T>::getLastElement() {

}
template<class T>
typename DoubleList<T>::ListNode* DoubleList<T>::getElement(int i) {

}
template<class T>
typename DoubleList<T>::ListNode* DoubleList<T>::locateData(T& val) {

}
template<class T>
typename DoubleList<T>::Status DoubleList<T>::cycledList() {
    Status st = OK;

    return st;
}
template<class T>
bool DoubleList<T>::isCycleList() {

}
template<class T>
typename DoubleList<T>::Status DoubleList<T>::clearList() {

}
template<class T>
DoubleList<T>& DoubleList<T>::operator=(const DoubleList<T>& dlist) {

}
template<class T>
typename DoubleList<T>::ListNode& DoubleList<T>::operator[](int i) {

}
template<class T>
const typename DoubleList<T>::ListNode& DoubleList<T>::operator[](int i) const {

}
template <class U>
ostream& operator<<(ostream& os, const DoubleList<U> list);
#endif
