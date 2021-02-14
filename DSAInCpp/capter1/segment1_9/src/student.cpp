#include "student.h"
#include <iostream>

using namespace std;
Student::Student(): majorLen(10){
    Personal();
    major = new char[majorLen+1];
}
Student::Student(char* ssn, char* n, char* c, int y, long s, char* maj):majorLen(11){
    Personal(ssn, n, c, y, s );
    major = new char[majorLen + 1];
    strcpy(major, maj);
}
Student::~Student() {
    if(major != nullptr) {
        delete[] major;
    }
}

void Student::writeToFile(fstream& fs) const {
    Personal::writeToFile(fs)  ;
    fs.write(major, majorLen);
}

void Student::readFromFile(fstream& fs) {
    Personal::readFromFIle(fs);
    fs.read(major, majorLen);
}

int Student::size() const {
    return Personal::size() + majorLen;
}
ostream& Student::writeLogibly(ostream& os) {
    major[majorLen] = '\0';
    Personal::writeLegibly(os);
    os << ", major: "<< major;
    return os;
}

ostream& operator<<(ostream& os, Student& stu){
    return stu.writeLegibly(os);
}

istream& Student::readFromConsoled(istream& is) {
    char s[80];
    major[majorLen] = '\0';
    Personal::readFromConsoled(is);
    cout << "major: ";
    is.getline(s, 80);
    strncpy(major, s, majorLen);
    is.ignore();
    return is;

}
istream& operator>>(istream& is, Student& stu) {
    return stu.readFromConsoled(is);
}