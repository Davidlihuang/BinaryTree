#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Person{
public:
    Person(string s,  int a = 0) {
        this->name = s;
        this->age = a;
    }
    ~Person() {

    }
    bool operator==(const Person& p) const;
    bool operator<(const Person& p) const;
    bool operator>(const Person& p) const;
    friend ostream& operator<<(ostream& os, const Person& p);
private:
    string name;
    int age;
    friend bool lesserAge(const Person&,  const Person&);
};

void testCase();