#ifndef CIRCLEQUEUE_H_
#define CIRCLEQUEUE_H_
#include <iostream>

template <class T, int size>
class CircleQueue
{
private:
    T data[size];
    int first;
    int last;

public:
    CircleQueue() : first(0), last(0) {}
    ~CircleQueue() {}

    bool isEmpty() const { return (first ==last); }
    bool isFull() const { return (first == (last + 1 + size) % size); }
    int capacity() const { return size-1; }
    int queueSize() const
    {
        if (isEmpty())
        {
            return 0;
        }
        else if (first < last)
        {
            return last - first;
        }
        else
        {
            return (last + size) - first;
        }
    }

    T &front()
    {
        if(!isEmpty())
        {
            return data[first];
        }
        else
        {
            throw "get front from an empty queue...";
        }
    }
    T &back()
    {
            if( !isEmpty() )
            {
                return data[last-1];
            }
            else
            {
                throw "get back from an empty queue...";
            }
    }
    void push_back(const T &element)
    {
        if(isFull())
        {
            throw "full queue can't not push element...";
            return ;
        }
        else{
            data[last] = element;
            last = (last + 1 + size) % size;
        }
    }
    T pop_front()
    {
        T element;
        if(isEmpty())
        {
            throw "pop element from empty queue...";
        }
        else
        {
            element = data[first];
            first = (first + 1 + size ) % size;
            return element;
        }
        
    }
};

#endif
