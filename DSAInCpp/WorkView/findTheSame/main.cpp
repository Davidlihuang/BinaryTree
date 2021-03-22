#include <iostream>
#include <string>
#include <vector>
#include "bubbleSort.h"
#include <set>


//时间复杂度O(n)、 空间复杂度O(n)
using namespace std;
int* findTheSame(int data[], int n)
{
    set<int> dataSet;
    for(int i=0; i< n; i++)
    {
        if( dataSet.count(data[i])) return &data[i];
        dataSet.insert(data[i]);
    }
    return nullptr;
}

//空间复杂度O(1), 时间复杂度O(n)
//只是重复一次的解法
int findTheSame2(int data[], int n)
{
    int upSum = n*(n+1)/2;
    int trueSum  = 0;
    int res = 0;

    for(int i = 0; i< n; i++)
    {
        trueSum += data[i];
    }
    
    res = n - (upSum - trueSum);
    return res;
}


using namespace std;
int main(int argc, char* argv[])
{
    int data[]{1,2,6,3,4,5,6};
    int* d;
    d = findTheSame(data, sizeof(data)/sizeof(int));
    cout <<*d << endl;
    cout <<findTheSame2(data,sizeof(data)/sizeof(int)) << endl;
    return 0;
}