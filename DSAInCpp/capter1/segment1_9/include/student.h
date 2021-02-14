#ifndef STUDENT_H_
#define STUDENT_H_
#include "personal.h"

class Student: Personal{
public:
    Student();
    Student(char*, char*, char*, int, long, char*);
    ~Student();
    void writeToFile(fstream&) const;
    void readFromFile(fstream&);
    int size() const;

protected:
    const int majorLen;
    char* major;
    ostream& writeLogibly(ostream&);
    friend ostream& operator<< (ostream&, Student&);
    istream& readFromConsoled(istream&);
    friend istream& operator>>(istream&, Student&);
};
#endif