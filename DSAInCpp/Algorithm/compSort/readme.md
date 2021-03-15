## 4. 梳排序
- 基本思想：
- 伪代码：
- 代码
```cpp
template <class T>
void compSort(T data[], int n)
{
    //预处理数据
    int step = n;
    while ((step = int(step / 1.3)) > 1)
    {
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
```
- 时间复杂度分析