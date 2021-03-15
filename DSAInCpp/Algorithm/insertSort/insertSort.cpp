#include <iostream>
using namespace std;


//升序排列
template <typename T>
void insertSort(T data[], int n)
{
    T temp;
    for (int i = 1, pos ; i < n; i++)
    {
        temp = data[i];
        for(pos = i ; pos > 0 && temp < data[pos-1];  pos--)
        {
            data[pos] = data[pos-1];
        }
        data[pos] = temp;
    }
}

template <typename T>
void printList(T data[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main()
{
    int data[]{2, 7, 8, 9, 7, 6, 56, 8, 56, 78, 65, 35};
    int len = sizeof(data)/sizeof(int);
    cout <<"origin: ";
    printList(data, len);
    insertSort(data, len);
    cout <<"after sort: ";
    printList(data, len);
    return 0;
}