#ifndef PERSONAL_H_
#define PERSONAL_H_
#include <fstream>
#include <iostream>
#include <cstring>


class Personal
{
public:
    Personal();
    Personal(char *, char *, char *, int, long);
    ~Personal();
    void writeToFile(std::fstream &) const;
    void readFromFIle(std::fstream &);
    void readKey();
    int size() const;

protected:
    const int nameLen, cityLen;
    char SSN[10], *name, *city;
    int year;
    long salary;
    std::ostream &writeLegibly(std::ostream &);
    friend std::ostream &operator<<(std::ostream &, Personal &);
   std::istream &readFromConsoled(std::istream &);
    friend std::istream &operator>>(std::istream &, Personal &);
};

#endif