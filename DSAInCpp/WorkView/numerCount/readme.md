# 元戎启行面试题
## 题目描述：
    有一个数n，对n从高位到低位计算相同数据项的个数比如有以下形式：
    n = 11 -> res = 21;   代表有2个1
    n = 331112 -> res = 233112 

## 思路
    使双指针解法：
        left和right的字符如果相同那么right++,直到遇到一个不相等的字符时right停止自增，统计个数 = right -left
        将结果写入res = res + std::to_string(right-left) + str[left], 遍历一遍后就可以得到结果
## 代码
```cpp
string numCounter(int n)
{
    string str = std::to_string(n);
    int left = 0, right = 0;
    int Len = str.size();
    cout <<"str: "<<str <<"strLen: " <<Len << endl;
    string res;
    while(right < str.size()) 
    {
        while ( str[left] ==  str[right] ) right++;
        res = res + std::to_string(right-left)+ str[left];
        left = right;
    }
    return res;
}

```
## 注意要点
    1. 数字转字符，字符转数字-->弱项
    2. map的熟练应用
    3. 边界条件的思索
 
