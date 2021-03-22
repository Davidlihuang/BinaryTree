# 字节一面题目
题目描述：提供一个整数n，将n转化为三进制数后，如$$(27)3 = 1000.从右到左输出1，2，3，5，8...位的三进制位。

如： (27)3 = 1000 那么输出 000 
如：(5)3 = 12  那么输出的是21


```cpp
void helper(int n)
{
    stack<int> res;
    int i = 1, dp1 = 0, dp2 = 1;
    //完成进制转换
    cout << "origin res: ";
    while (n != 0)
    {
        int tmp = dp1 + dp2;
        //符合斐波那契数列的项入栈
        if (i == tmp){ res.push(n % 3); dp1 = dp2; dp2 = tmp; } 
        cout << n % 3 << " ";
        n = n / 3;
        ++i;
    }
    cout << endl;
    cout << "result: ";
     //将结果出栈，打印就可以得到想要的结果了
    while (!res.empty()) 
    {
        cout << res.top() << " ";
        res.pop();
    }
    cout << endl;
    //逆序输出
}

```