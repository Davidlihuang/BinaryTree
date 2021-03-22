#ifndef BUBBLESORT_H_
#define BUBBLESORT_H_

#include <iostream>
/*******************************************************************
 *   
 * 
 * ******************************************************************/
template <typename T>
void bubbleSort(T &data, size_t length, bool option)
{
    for (size_t i = 0; i < length - 1; i++)
    {
        for (size_t j = 0; j < length - 1 - i; j++)
        {
            if (option)
            {
                if (data[j] > data[j + 1])
                {
                    using std::swap;
                    swap(data[j], data[j + 1]);
                }
            }
            else
            {
                if (data[j] < data[j + 1])
                {
                    using std::swap;
                    swap(data[j], data[j + 1]);
                }
            }
        }
    }
}
/**********************************************************
*
**********************************************************/
template <typename U>
void bubbleSortOpt(U &data, size_t length, bool option)
{
    int m = 0;
    bool flag = true;
    while ((m < length - 1) && flag == true)
    {
        flag = false;
        for (size_t j = 0; j < length - 1 - m; j++)
        {
            if (option)
            {
                if (data[j] > data[j + 1])
                {
                    using std::swap;
                    flag = true;
                    swap(data[j], data[j + 1]);
                }
            }
            else
            {
                if (data[j] < data[j + 1])
                {
                    using std::swap;
                    flag = true;
                    swap(data[j], data[j + 1]);
                }
            }
        }
        ++m;
    }
}

template <typename K>
void printList(std::ostream &os, K &data)
{
    for (auto c : data)
    {
        os << c << " ";
    }
}

#endif