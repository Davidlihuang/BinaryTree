#ifndef STRINGDELETE_H_
#define STRINGDELETE_H_
#include <iostream>
#include <string>
#include <set>
#include <fstream> 
#include <sstream>
#include "createdata.h"

using namespace std;
void strDelete(string &sourceFilename, string& resultFilename)
{

    fstream filein(sourceFilename, ios::in);

    fstream fileout(resultFilename, ios::out);
    fileout.close();
    fileout.open(resultFilename, ios::out|ios::app);
    
    string str;
    set<string> dataSet;
    string tmpStr;
    long sum = 0;
    while(getline(filein, str))
    {
        
        //去掉，号
        for(auto &c:str)
        {
            if(c==','|| c=='\n') c=' ';
        }

        //拆分
        stringstream sstr(str);
        while(getline(sstr, tmpStr,' '))
        {
            if(!dataSet.count(tmpStr))
            {
                sum++;
                dataSet.insert(tmpStr);
                fileout<<tmpStr<<" ";
                if(sum%30 == 0)  fileout <<"\n";
            }
            cout << " - ";
        }
        cout << endl;
    }

    cout << "\nset.size():"<< dataSet.size() << endl;
    filein.close();
    fileout.close();
}
#endif