#ifndef SINGLELISTTEMP_H_
#define SINGLELISTTEMP_H_
#include <iostream>
template <class N>
struct ListNode
{
    ListNode() : next(nullptr){};
    ListNode(N element, ListNode *nx = nullptr) : data(element),
                                                  next(nx){};

    N data;
    ListNode *next;
};

template <class T>
class SingleList
{
public:
    SingleList()
    {
        head = tail = nullptr;
    };
    ~SingleList();

    bool isEmpty() { return head == nullptr; };
    void addToHead(const T &elem);
    void addToTail(const T &elem);
    void insertElement(const T &elem, size_t position);

    T deleteFromHead();
    T deleteFromTail();
    T deletePositonElement(size_t positon);
    void deleteElement(T elem);

    bool find(const T elem);
    size_t size();
    void printList(std::ostream &os);

    //1、类内实现友元
    /*
    friend std::ostream& operator<<(std::ostream& os, SingleList<T>& list) 
    {
       list.printList(os);
        return os;
    }    
    */
    //2. 单独模板类外实现
    template <typename U>
    friend std::ostream &operator<<(std::ostream &os,  SingleList<U>& lis);


private:
    ListNode<T> *head;
    ListNode<T> *tail;
};

template <typename U>
std::ostream &operator<<(std::ostream &os, SingleList<U>& list)
{
    list.printList(os);
    return os;
}

template <typename T>
SingleList<T>::~SingleList()
{
    while (!isEmpty())
    {
        deleteFromHead();
    }
}

template <typename T>
void SingleList<T>::addToHead(const T &elem)
{
    if (isEmpty())
    {
        head = tail = new ListNode<T>(elem);
    }
    else
    {
        head = new ListNode<T>(elem, head);
    }
}

template <typename T>
void SingleList<T>::addToTail(const T &elem)
{
    if (isEmpty())  
    {
        head = tail = new ListNode<T>(elem);
    }
    else
    {
        tail->next = new ListNode<T>(elem, tail->next);
        tail = tail->next;
    }
}

template <typename T>
void SingleList<T>::insertElement(const T &elem, size_t position)
{
    size_t pos = size();

    if (!isEmpty() && (position > 0 && position <= pos))
    {
        if (1 == position)
        {
            addToHead(elem);
        }
        else if (pos == position)
        {
            addToTail(elem);
        }
        else
        {
            ListNode<T> *tmp = head;
            for (int i = 0; i < position - 2; i++)
            {
                tmp = tmp->next;
            }
            ListNode<T> *newNode = new ListNode<T>(elem, tmp->next);
            tmp->next = newNode;
        }
    }
}

template <typename T>
T SingleList<T>::deleteFromHead()
{
    T elem;
    if (!isEmpty())
    {
        elem = head->data;
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            ListNode<T> *tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    return elem;
}

template <typename T>
T SingleList<T>::deleteFromTail()
{
    T elem;
    if (!isEmpty())
    {
        elem = tail->data;
        if (head == tail)
        {
            delete tail;
            tail = head = nullptr;
        }
        else
        {
            ListNode<T> *pre = head;
            while (pre->next != tail)
            {
                pre = pre->next;
            }
            delete tail;
            tail = pre;
        }
    }
    return elem;
}

template <typename T>
T SingleList<T>::deletePositonElement( size_t positon)
{
    T elem;
    size_t listSize = size();
    if (!isEmpty() && (positon > 0 && positon <= listSize))
    {
        if (positon == 1)
        {
            deleteFromHead();
        }
        else if (positon == listSize)
        {
            deleteFromTail();
        }
        else
        {
            ListNode<T> *pre = head;
            ListNode<T> *cur = head->next;
            for (int i = 0; i < positon - 2; i++)
            {
                pre = pre->next;
            }
            cur = pre->next;
            elem = cur->data;
            pre->next = cur->next;
            delete cur;
        }
    }
    return elem;
}

template <typename T>
void SingleList<T>::deleteElement(T elem)
{

    if (isEmpty())
        return;
    if (head->data == elem)
    {
        deleteFromHead();
    }
    else if (tail->data == elem)
    {
        deleteFromTail();
    }
    else if (head != tail)
    {
        ListNode<T> *pre = nullptr;
        ListNode<T> *cur = head;
        while (cur != nullptr)
        {
            if (cur->data == elem)
            {
                ListNode<T> *temp = cur;
                pre->next = cur->next;
                delete temp;
            }
            pre = cur;
            cur = cur->next;
        }
    }
}

template <typename T>
bool SingleList<T>::find(const T elem)
{
    bool isfind = false;
    if (!isEmpty())
    {
        ListNode<T> *tmp = head;
        while (tmp != nullptr)
        {
            if (tmp->data == elem)
                isfind = true;
            tmp = tmp->next;
        }
    }

    return isfind;
}

template <typename T>
size_t SingleList<T>::size()
{
    size_t listSize = 0;
    if (!isEmpty())
    {
        ListNode<T> *tmp = head;
        while (tmp != nullptr)
        {
            ++listSize;
            tmp = tmp->next;
        }
    }
    return listSize;
}

template <typename T>
void SingleList<T>::printList(std::ostream &os)
{
    if (isEmpty())
        return;
    ListNode<T> *temp = head;
    while (temp != nullptr)
    {
        os << temp->data << " ";
        temp = temp->next;
    }
}


#endif