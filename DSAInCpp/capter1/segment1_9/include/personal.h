#ifndef PERSONAL_H_
#define PERSONAL_H_
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;
class Personal
{
public:
    Personal();
    Personal(char *, char *, char *, int, long);
    ~Personal();
    void writeToFile(fstream &) const;
    void readFromFIle(fstream &);
    void readKey();
    int size() const;

protected:
    const int nameLen, cityLen;
    char SSN[10], *name, *city;
    int year;
    long salary;
    ostream &writeLegibly(ostream &);
    friend ostream &operator<<(ostream &, Personal &);
    istream &readFromConsoled(istream &);
    friend istream &operator>>(istream &, Personal &);
};

#endif