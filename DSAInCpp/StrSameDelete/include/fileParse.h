#ifndef FILEPARSE_H_
#define FILEPARSE_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct dataNode
{
    string label;
    string type;
    string dummy;
    string tclCmd;
};

class stringSparse
{

private:
    string title;
    string subtitle;
    vector<dataNode> Data;
    bool isValidTxt(const string &filename);    
    inline void  deleInvalidChart(string& tmp);
    void  splitdata(const string &tmpStr, vector<string>& res);
    void matchMyData(vector<string> & res);

public:
    void sparseData(const string &srcFilename);
    void printData() {
        cout << title<<":" << subtitle<<endl;
        int i=0;
        for(auto c: Data)
        {
            i++;
            cout << "CmdItem"<< i <<":" \
            <<" label="<<c.label<<","\
            <<" Type="<<c.type<<","\
            <<" Dummy="<<c.dummy<<","\
            <<" tclCmd="<<c.tclCmd<<","\
            << endl;
        }
    }
};






#endif