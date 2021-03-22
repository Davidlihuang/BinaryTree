#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include "fileParse.h"
using namespace std;

//格式检查
bool stringSparse::isValidTxt(const string &filename)
{
    stack<char> myStack;
    string tmp;
    fstream in(filename, ios::in);
    while (getline(in, tmp))
    {
        for (char c : tmp)
        {
            if (c == '{')
            {
                myStack.push(c);
            }
            else if (!myStack.empty() && c == '}' && myStack.top() == '{')
            {
                myStack.pop();
            }
        }
    }
    return myStack.empty();
}

//制表符替换成空格
void stringSparse::deleInvalidChart(string &tmp)
{
    //除去其他制表符
    for (auto &c : tmp)
    {
        if (c == '\t' || c == '\n' || c == '\v' || c == '\r')
        {
            c = ' ';
        }
        else if (c == '#' || c == '{' || c == '}')
        {
            tmp.clear();
        }
    }
}

//将一行字符串分解为单个指令并存储在res中
void stringSparse::splitdata(const string &tmpStr, vector<string> &res)
{
    string s1;
    stringstream sstr(tmpStr);
    while (getline(sstr, s1, ' '))
    {
        if (s1.size() != 0)
        {
            res.push_back(s1);
        }
    }

    //重新组合
    for (int i = 0; i < res.size() - 1; i++)
    {
        string &str = res[i];
        string &str1 = res[i + 1];
        if (str[0] == '\"' && str1[str1.size() - 1] == '\"')
        {
            str = str + " " + str1;
            str1.clear();
        }
    }
}

//数据存入结构体中
void stringSparse::matchMyData(vector<string> &res)
{
    stack<string> st;
    dataNode data;
    int opt = 0;
    if (res.size() < 2)
        return;
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i].empty())
            continue;
        else
        {
            if (res[i][0] == '\"' && res[i][res[i].size() - 1] == '\"')
            {
                string tmp(res[i].begin() + 1, res[i].end() - 1);
                st.push(tmp);
            }
            else
            {
                st.push(res[i]);
            }
        }
    }
    while (!st.empty())
    {
        data.tclCmd = st.top();
        if (st.empty())
            break;
        st.pop();
        data.dummy = st.top();
        if (st.empty())
            break;
        st.pop();
        data.type = st.top();
        if (st.empty())
            break;
        st.pop();
        data.label = st.top();
        if (st.empty())
            break;
        st.pop();
    }
    Data.push_back(data);
}

//解析文本
void stringSparse::sparseData(const string &srcFilename)
{
    if (!isValidTxt(srcFilename))
        return;

    //获取每行指令, 并解析所有指令
    string tmp;
    fstream in(srcFilename, ios::in);
    int num = 0;
    while (getline(in, tmp))
    {

        //替换其余制表符为
        deleInvalidChart(tmp);
        //单词拆分
        vector<string> result;
        if (tmp.size() != 0)
        {
            splitdata(tmp, result);
        }

        // 匹配
        if (result.empty() == 0 && result[0] == "Menu")
        {
            title = result[0];
            subtitle = result[1];
        }
        if (result.size() > 2)
        {
            matchMyData(result);
            num++;
        }
    }
}
