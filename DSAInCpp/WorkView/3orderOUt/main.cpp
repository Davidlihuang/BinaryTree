#include <iostream>
#include <stack>

using namespace std;

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

int main()
{
    helper(99);
    return 0;
}
