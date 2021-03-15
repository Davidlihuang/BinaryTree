#include <iostream>
#include <string>

using namespace std;

//打印结果
template <class T>
void printArray(T data[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

template <class T>
void compSort(T data[], int n)
{
    //预处理数据
    int step = n;
    while ((step = int(step / 1.3)) > 1)
    {
        /*
        for(int j = n-1, k = 0; j >= step; j-- )
        {
            
            k = j - step;
            if( data[j] < data[k])
            {
                cout << "change: ( " << j <<", " << k << " )"<<\
                                 "data( " << data[j] <<  ", " << data[k]<< " )"<<endl; 
                swap(data[j], data[k]);
            }

        }*/
        for (int j = 0, k = 0; j < n - step; j++)
        {
            k = j + step;
            if (data[j] > data[k])
            {
                cout << "change: ( " << j << ", " << k << " )"
                     << "data( " << data[j] << ", " << data[k] << " )" << endl;
                swap(data[j], data[k]);
            }
        }
        cout << "setp: " << step << " " << endl;
        printArray(data, n);
    }
    //冒泡排序
    bool loopFlag = true;
    for (int i = 0; i < n && loopFlag; i++)
    {
        loopFlag = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (data[j] > data[j + 1])
            {
                swap(data[j + 1], data[j]);
                loopFlag = true;
            }
        }
    }
}

int main()
{
    int data[19]{41, 11, 18, 7, 16, 25, 4, 23, 32, 31, 22, 9, 1, 22, 3, 7, 31, 6, 10};
    int length = sizeof(data) / sizeof(int);
    printArray(data, length);
    compSort(data, length);
    printArray(data, length);
    return 0;
}