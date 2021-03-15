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
//selectSort

template<typename T>
void selectSort(T data[], int n, bool opt=true)
{
    for(int i = 0; i < n-1; i++)
    {
        int least = i;
        for(int k = i+1; k< n; k++)
        {
            if(data[k] < data[least] && opt)
            {
                least = k;
            }
            else if(data[k] > data[least] && !opt)
            {
                least = k;
            }
        }
        swap(data[i], data[least]);
    }
}

int main()
{
    int data[]{47, 0, 45, 89,12,1,23, 12};
    int n = sizeof(data) / sizeof(int);
    printArray(data, n);
    selectSort(data, n, true);
    cout << "result: ";
    printArray(data, n);
    return 0;
}