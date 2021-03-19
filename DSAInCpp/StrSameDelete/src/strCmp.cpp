#include <iostream>
#include <vector>
#include "strCmp.h"

using namespace std;
int strLen(const char *cstr)
{
    if (cstr == nullptr)
        return 0;
    int Len = 0;
    const char *iter1st = cstr;
    while (*iter1st != '\0')
    {
        iter1st++;
        Len++;
    }
    return Len;
}
int s_int(const char *cstr, int first, int second)
{
    if (cstr == nullptr)
        return -1;
    int nLen = (second - first) - 1;
    int result = 0;
    for (int i = first; i < second && nLen > 0; i++)
    {
        int Plu = 10;
        for (int i = 0; i < nLen - 1; i++)
        {
            Plu *= 10;
        }
        result = result + (int(cstr[i]) - 48) * Plu;
        nLen--;
    }
    result = result + int(cstr[second - 1]) - 48;
    return result;
}
vector<int> checkNumber(const char *cstr)
{
    if (cstr == nullptr)
        return {};
    int Len = strLen(cstr);
    int min = 0, max = 0;
    vector<int> index;
    for (int i = 0; i < Len;)
    {
        if (cstr[i] >= '0' && cstr[i] <= '9')
        {
            max = min = i;
            while (cstr[max] >= '0' && cstr[max] <= '9' && max < Len)
                max++;
            index.push_back(min);
            index.push_back(max);
            int result = s_int(cstr, min, max);
            index.push_back(result);

            i = min = max;
            continue;
        }
        else
        {
            ++i;
        }
    }
    return index;
}
bool strcmpWithDigital(const char *c1st, const char *c2nd)
{
    // 全字母
    if (c1st == nullptr || c2nd == nullptr)
        return false;
    int c1stLen = strLen(c1st);
    int c2ndLen = strLen(c2nd);
    // 得到字符串中的数字所在的坐标和其值
    vector<int> res1 = checkNumber(c1st);
    vector<int> res2 = checkNumber(c2nd);
    //分情况比较

    //1. 全是字符
    if (res1.empty() && res2.empty())
    {
        int id = 0;
        int minLen = (c1stLen < c2ndLen) ? c1stLen : c2ndLen;
        while (id != minLen)
        {
            if (c1st[id] > c2nd[id])
                return false;
        }
    }
    //2. 都含有数字
    else if (res1.empty() == false && res2.empty() == false)
    {
        const char *temp1 = c1st;
        const char *temp2 = c2nd;
        int nums1 = res1.size() / 3;
        int nums2 = res2.size() / 3;
        int min = 0, max = 0, digital = 0;
        int maxNum = (nums1 > nums2) ? nums1 : nums2;

        for (int i = 0; i < maxNum; i++)
        {
            // 每个数字前的一段
            min = 3 * i;
            max = 3 * i + 1;
            digital = 3 * i + 2;

            int flag1 = 0, flag2 = 0;
            int diff1 = res1[min] - flag1;
            int diff2 = res2[min] - flag2;

            if (diff1 == diff2)
            {
                while (*temp1 != c1st[res1[min]])
                {
                    if (*temp1 > *temp2)
                        return false;
                    temp2++;
                    temp1++;
                }

                if (res1[digital] > res2[digital])
                    return false;

                temp1 = temp1 + (res1[max] - res1[min]);
                temp2 = temp2 + (res2[max] - res2[min]);
                flag1 = res1[max];
                flag2 = res2[max];
            }
            else if (diff1 != diff2)
            {
                //数字不对齐
                if (diff1 < diff2)
                {
                    while (*temp1 != c1st[res1[min]])
                    {
                        if (*temp1 > *temp2)
                            return false;
                        temp1++;
                        temp2++;
                    }
                    if (*temp2 < '0' || *temp2 > '9')
                        break;
                }
                else
                {
                    while (*temp2 != c2nd[res2[min]])
                    {
                        if (*temp1 > *temp2)
                            return false;
                        temp1++;
                        temp2++;
                    }
                    if (*temp1 < '0' || *temp1 > '9')
                        break;
                }
            }
        }
    }
    // 只有一个字符串有数字，从第一个数字阶段，比较前半序列
    else
    {
        if (res1.empty() && !res2.empty())
        {

            if (c1stLen < res2[0])
            {
                for (int i = 0; i < c1stLen; i++)
                {
                    if (c2nd[i] < c1st[i])
                        return false;
                }
            }
            else
            {
                for (int j = 0; j < res2[0]; j++)
                {
                    if (c2nd[j] < c1st[j])
                        return false;
                }
            }
        }
        else
        {

            if (c2ndLen < res1[0])
            {
                for (int i = 0; i < c2ndLen; i++)
                {
                    if (c2nd[i] < c1st[i])
                        return false;
                }
            }
            else
            {
                for (int j = 0; j < res1[0]; j++)
                {
                    if (c2nd[j] < c1st[j])
                        return false;
                }
            }
        }
    }

    return true;
}
