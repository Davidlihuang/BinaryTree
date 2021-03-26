#include <iostream>
#include <vector>

using namespace std;
void Merge(vector<int> &data, int low, int mid, int hight)
{
    int leftStart = low, rightStart = mid + 1, k = 0;
    vector<int> temp(hight - low + 1);
    //合并两个有序的子序列，存放在一个临时空间中
    while (leftStart <= mid && rightStart <= hight)
    {
        if (data[leftStart] < data[rightStart])
            temp[k++] = data[leftStart++];
        else
            temp[k++] = data[rightStart++];
    }
    //不等长的部分直接复制过来
    while (leftStart <= mid)
        temp[k++] = data[leftStart++];
    while (rightStart <= hight)
        temp[k++] = data[rightStart++];

    //修改data数据
    for (int i = low, k = 0; i <= hight; i++, k++)
        data[i] = temp[k];
}

void mergeSort(vector<int> &data, int first, int last)
{
    if (first >= last)
    {
        return;
    }
    int mid = first + (last - first) / 2; //避免溢出
    mergeSort(data, first, mid);          //分
    mergeSort(data, mid + 1, last);
    Merge(data, first, mid, last); //治
}

void insertSort(vector<int> &data, int low, int high)
{
    int temp;
    int len = high - low;
    for (int i = low + 1, pos; i < len; i++)
    {
        temp = data[i];
        for (pos = i; pos > low && temp < data[pos - 1]; pos--)
        {
            data[pos] = data[pos - 1];
        }
        data[pos] = temp;
    }
}

//优化1
void mergeSort1(vector<int> &data, int low, int high)
{
    if (high - low <= 10)
    {
        insertSort(data, low, high);
        return;
    }
    int mid = low + (high - low) / 2;
    mergeSort1(data, low, mid);
    mergeSort1(data, mid+1, high);
    Merge(data, low, mid, high);
}

//优化2
void mergeSort2(vector<int> &data, int low, int high)
{
    if( low >= high) return;
    int mid = low + (high - low)/2;
    mergeSort2(data, low, mid);
    mergeSort2(data, mid+1, high);
    if(data[mid] < data[mid+1]) return;
    Merge(data, low, mid, high);
}

int main()
{
    vector<int> data{2, 5, 1, 4, 2, 3, 6, 5, 5, 55, 6};

    for (auto c : data)
        cout << c << " ";
    cout << endl;
    mergeSort2(data, 0, data.size() - 1); //第一个元素， 最后一个元素的下标
    for (auto c : data)
        cout << c << " ";
    cout << endl;
    return 0;
}