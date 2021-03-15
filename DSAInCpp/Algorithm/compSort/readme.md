## 4. 梳排序
- 基本思想：
1. 数据预处理到大致有序 + 冒泡排序

2. 预处理的方式是：
	- 设定一个补偿step = int(step/**1.3**)，将[0, n-step]区域和 [step, n]区域中不如果data[j+step]和data[j]满足排序标准，两两交换。
	- 直到step 小于或者等于1 时候停止预处理。
	- 预处理完成后，整个序列将大致有序，能降低冒泡排序算法执行时间
	
3. 执行冒泡排序，设定排序标志，如果没有发生交换直接可以直接跳过外层循环

- 预处理中step的系数选择1.3的原因：
	
	- 元素间距：$\lfloor\frac{n}{s}\rfloor, \lfloor\frac{\lfloor\frac{n}{s} \rfloor}{s} \rfloor, ...$  近似于等比数列： $\frac{n}{s}, \frac{n}{s^2}, \frac{n}{s^3},...,\frac{n}{s^p}$  其中$p$ 为step除的次数
	
	- **能够确保最后一步$\frac{n}{s^p}  = 2$ **所以 $p = \frac{lg\frac{n}{2}}{lg s} $
	
- 预处理阶段时间复杂度$O(nlogn)$：

  外层循环执行次数：$p$

  内层循环比较次数分别为 $\frac{n}{s}, \frac{n}{s^2}, \frac{n}{s^3},...,\frac{n}{s^p}$ 

  预处理阶段总比较次数为：$n\sum_{i=1}^{p}(1-\frac{1}{s^i}) = p\cdot n- \frac{2-n}{1-s} = n\cdot \frac{lg\frac{n}{2}}{lg s} - \frac{2-n}{1-s}$

- 伪代码：
```txt
void compSort(data[], n)
	预处理:step初始值为n
	设定step = step/1.3，只要step大于1就进行[0, n-step]和[step, n]数据比较交换
	冒泡排序
```

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
```txt
最坏情况取决于冒泡排序： $O(n^2)$
最好情况：$O(nlogn)$
```