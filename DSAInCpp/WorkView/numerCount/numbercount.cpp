#include <iostream>
#include <string>

using namespace std;
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

int main()
{
    string res;
   res = numCounter(22113);
    cout <<res<< endl;
    return 0;
}