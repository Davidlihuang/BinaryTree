# 归并排序
## 算法思路：

## 解题方案
### 递归法- 自顶向下
```cpp
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
```
### 迭代法-自底向上
## 优化方法
### 1. 对于小规模的数组使用插入排序
- 思路
    用不同规模的方法处理小规模的问题，能改进大多数递归算法的性能，因为递归会使得小规模问题中方法调用太过于频繁，所以改进它的处理方法就能改进整个算法
- 方法
  - ①、终止条件
  - ②、插入排序放置的位置
-  代码
  ```cpp
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
  ```
### 2. 测试待排序序列中左右半边是否有序（左边所有的数小于右边所有的数）

- 避免合并方法的调用
  
```txt
    因为a[low, mid] 和a[mid+1, high]本来就是有序的。存在a[low]<a[low+1]...< a[mid] 和 a[mid+1] <  a[mid +2] ...< a[high]那么只需要判断a[mid] < a[mid+1] ，我们认为数组在low到high之间就是有序的，不需要执行合并操作
```
- 更改方法

只需要在merge之前判断左右序列是否有序，如果有序直接return;
```cpp
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
```
