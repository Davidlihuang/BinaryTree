#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;
//递归形式
bool searchBinRecur(const vector<int>& data, int target, int low, int high)
{
    if(low > high) return false;
    int mid = low + (high - low)/2;
    if(data[mid] == target) return true;
    else if(data[mid] < target) searchBinRecur(data, target, mid+1, high);
    else searchBinRecur(data, target, low, mid-1);
}
//迭代形式
bool searchBin(const vector<int>& data,const int target)
{
    int low=0, high = data.size()-1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
	if(data[mid] == target) return true;
	else if(data[mid] < target) low = mid + 1;
	else high = mid - 1;
    }
    return false;
}

int main(int argc, int **argv)
{
    vector<int> data{1,2,3,4,5,6,7,8,9};
    int target = 5;
//    bool isfinded =  searchBin(data, target);
    bool isfinded = searchBinRecur(data, target, 0, data.size()-1);
    printf("find(%d)= %d\n", target, isfinded);
           
    return 0;
}
