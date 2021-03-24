#include <iostream>
#include <vector>

using namespace std;
void quickSort(vector<int>& data, int left, int right)
{
    if (left >= right) return;
    int i = left, j = right, base = data[left];
    while(i< j)
    {
        while (data[j] >= base && i<j) //找右边小于基准值的数
        {
            j--;
        }
        while(data[i] <= base && i<j) //找左边大于基准值的数
        {
            i++;
        }
        if(i < j) std::swap(data[i], data[j]);
    }
    data[left] = data[i];
    data[i] = base;
    quickSort(data, left, i-1);
    quickSort(data, i+1, right);
}

int main()
{
    vector<int> d{2,5,4,2,1,3,6,8,5,1};
    quickSort(d, 0, d.size()-1);
    for(auto c :d) cout << c << " ";
    cout<< endl;
    return 0;
}