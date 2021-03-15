## 2. 选择排序
- **基本思想**：每一趟从待排列的记录中选出关键字最小的纪律，按顺序放在已经排序的记录序列的最后，直到全部排完为止。
- **算法步骤**：数据共n项目，data[0]--data[n-1]
	- ①、第一趟从data[0]开始，通过n-1次比较。从0-（n-1）中选择最小的元素data[k]，交换data[0]和data[k]的值；
	- ②、第二趟从data[1]开始，通过n-2次的比较。从1-(n-1) 中选择最小的元素data[k],交换data[1] 和data[k]。
	- ③、以此类推，从第$i$从data[i]开始，通过n-1-i次的比较，从i-(n-1)中选择最小的元素data[k]，交换data[i]和data[k]。
	- ④、通过n-1趟后，排序完成
- **伪代码**：
```cpp
selectSort(data[],n)
	for i = 0到 n-2
		找出元素data[i],....,data[n-1]中的最小元素
		将其于data[i]交换
```
- **代码片段**：
 ```cpp
 template<class T>
 void selectSort(T data[], int n)
 {
 	for(int i = 0; i < n-1; i++)
 	{
 		int least =i;
 		for(int k = i+1; k < n; k++)
 		{
 			if( data[k] < data[i])
 				least = k;
 		}
 		if(i != least) //避免相同位置的元素进行没有必要的自我交换，导致大对象交换延迟
 		{
 			std::swap(data[i], data[least]);
 		}
 	}
 }
 ```
- **时间复杂度:** $O(n^2)$
①、分析：
比较次数： 无论什么情况比较次数都相等 $\sum_1^{n-1}i = \frac{n(n-1)}{n}$
		忽略掉赋值交换的$O(n)$低次操作，去最高次$O(n^2)$
	
- **空间复杂度：**$O(1)$ 

只有记录交换时需要一个辅助空间，所以空间复杂度时$O(1)$