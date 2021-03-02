#include <iostream>
#include "intSLList.h"

IntSLList::~IntSLList()
{
    IntSLLNode *p = nullptr;
    while (!isEmpty())
    {
        p = head;
        head = p->next;
        delete p;
    }
    tail = head;
}

void IntSLList::addToHead(int e)
{
    head = new IntSLLNode(e, head);
    if (tail == nullptr)
    {
        tail = head;
    }
}

void IntSLList::addToTail(int e)
{
    if (tail == nullptr)
    {
        head = tail = new IntSLLNode(e);
    }
    else
    {
        tail->next = new IntSLLNode(e);
        tail = tail->next;
    }
}
int IntSLList::deleteFromHead()
{
    int el;
    IntSLLNode *tmp;
    if (!isEmpty())
    {
        el = head->info;
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            tmp = head;
            head = tmp->next;
            delete tmp;
        }
    }
    return el;
}

int IntSLList::deleteFromTail()
{
    int el;
    IntSLLNode *tmp = head;
    if (!isEmpty())
    {
        el = tail->info;
        if (head == tail)
        {
            delete tail;
            tail = head = nullptr;
        }
        else
        {
            while (tmp->next != tail)
            {
                tmp = tmp->next;
            }
            delete tail;
            tail = tmp;
        }
    }
    return el;
}

void IntSLList::deleteNode(int e)
{
    if (!isEmpty())
    {
        //只有一个节点
        if (head == tail && e == head->info)
        {
            delete head;
            head = tail = nullptr;
        }
        // 第一节点就是
        else if (e == head->info)
        {
            IntSLLNode *tmp;
            tmp = head;
            head = tmp->next;
            delete tmp;
        }
        // 不在第一个节点，直接往后找。注意：最后一个元素尾指针要改变
        else
        {
            IntSLLNode *pre = head;
            IntSLLNode *tmp = head->next;
            while (tmp != nullptr && e != tmp->info)
            {
                tmp = tmp->next;
                pre = pre->next;
            }
            if (tmp != nullptr)
            {
                pre->next = tmp->next;
                if (tmp == tail)
                {
                    tail = pre;
                }
                delete tmp;
            }
        }
    }
}

bool IntSLList::isInList(int e) const
{
    IntSLLNode *tmp = head;
    while (tmp && tmp->info != e)
    {
        tmp = tmp->next;
    }
    if (tmp)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void IntSLList::print(std::ostream &os)
{
    if (!isEmpty())
    {
        IntSLLNode *tmp = head;
        while (tmp != nullptr)
        {
            os << tmp->info << " ";
            tmp = tmp->next;
        }
    }
    else
    {
        os << "EmptyList";
    }
}

std::ostream &operator<<(std::ostream &os, IntSLList &lis)
{
    lis.print(os);
    return os;
}