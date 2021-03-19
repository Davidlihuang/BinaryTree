#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <unordered_map>
#include <random>
#include <ctime>
#include "createdata.h"

using namespace std;
void createData(const string& filename, long limits, long range)
{
    srand(clock());
    string str;
    string character[]{" ",  "," };
    fstream file;
    file.open(filename, ios::out);
    for( long i=1; i <= limits; i++)
    {
        //long t = rand()%1000000;
        long t = rand()%range;
        str = to_string(t);
        file << str  << (t%2==0? " " :  ",");
        if(i%30 == 0)
        {
            file << "\n";
        }
    }
    file.close();
    return ;
}