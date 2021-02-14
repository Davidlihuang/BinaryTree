#ifndef STUDENT_H_
#define STUDENT_H_
#include "personal.h"

class Student: public Personal{
public:
    Student();
    Student(char*, char*, char*, int, long, char*);
   // ~Student();
    void writeToFile(std::fstream&) const;
    void readFromFile(std::fstream&);
    int size() const;

protected:
    const int majorLen;
    char* major;
    std::ostream& writeLogibly(std::ostream&);
    friend std::ostream& operator<< (std::ostream&, Student&);
    std::istream& readFromConsoled(std::istream&);
    friend std::istream& operator>>(std::istream&, Student&);
};
#endif