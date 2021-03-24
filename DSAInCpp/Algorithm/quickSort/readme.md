# 快速排序
## 算法描述
    通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分小，然后对两部分进行递归的快速排序。
## 算法步骤
    1. 从数组中挑出一个元素，称为“基准”（pivot）；
    2. 重新排序数组，所有比基准小的数放在基准前面，所有比基准大的元素放3. 在基准后面，这称为分区（partition）操作；
    4. 递归地对基准两边的子数组进行排序
## 代码
```cpp
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
```
## 时间和空间复杂度
    1. 时间复杂度： 最好O(nlog(n)) 最坏O(n^2)
    2. 空间复杂度：最好O(logn) 最坏O(n);