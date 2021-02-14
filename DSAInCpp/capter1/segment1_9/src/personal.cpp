#include "personal.h"

using namespace std;
Personal::Personal() : nameLen(10), cityLen(10)
{
    name = new char[nameLen + 1];
    city = new char[cityLen + 1];
}
Personal::Personal(char *ssn, char *n, char *c, int y, long s) : nameLen(10), cityLen(10)
{
    name = new char[nameLen + 1];
    city = new char[cityLen + 1];
    strcpy(SSN, ssn);
    strcpy(name, n);
    strcpy(city, c);
    year = y;
    salary = s;
}
Personal::~Personal(){
    if(name != nullptr)
        delete [] name;
    if(city != nullptr) 
        delete [] city;
}
void Personal::writeToFile(fstream &out) const
{
    out.write(SSN, 9);
    out.write(name, nameLen);
    out.write(city, cityLen);
    out.write(reinterpret_cast<const char*>(&year), sizeof(int) );
    out.write(reinterpret_cast<const char*>(&salary), sizeof(int));
}

void Personal::readFromFIle(fstream &in)
{
    in.read(SSN, 9);
    in.read(name, nameLen);
    in.read(city, cityLen);
    in.read(reinterpret_cast<char*>(&year), sizeof(int));
    in.read(reinterpret_cast<char*>(&salary), sizeof(int));
}

void Personal::readKey()
{
    char s[80];
    cout << "Enter the SSN: ";
    cin.getline(s, 80);
    strncpy(SSN, s, 9);
}

int Personal::size() const
{
    return (9 + nameLen + cityLen + sizeof(year) + sizeof(salary));
}

ostream &Personal::writeLegibly(ostream &os)
{
    SSN[9]  = name[nameLen] = city[cityLen] = '\0';
    os << "SSN = " << SSN << ", name = " << name 
          << ", city = " << city << ", year = "<<  year <<  ", salary = "<<salary;
    return os;
}

istream &Personal::readFromConsoled(istream &is)
{
    SSN[9]  = name[nameLen] = city[cityLen] = '\0';
    char s[80];
    cout<<"SSN: ";
    is.getline(s, 80);
    strncpy(SSN, s, 9);

    cout << "name: ";
    is.getline(s, 80);
    strncpy(name, s, nameLen);

    cout << "city: ";
    is.getline(s, 80);
    strncpy(city, s, cityLen);

    cout << "BirthYear:  ";
    is >> year;

    cout << "salary: ";
    is >> salary;

    is.ignore();
    return is;
    
}
ostream &operator<<(ostream &os, Personal &p)
{
    return p.writeLegibly(os);
}

istream &operator>>(istream &is, Personal &p)
{
    return p.readFromConsoled(is);
}
