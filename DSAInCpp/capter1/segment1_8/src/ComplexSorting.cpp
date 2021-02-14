#include <iostream>
#include <vector>
#include <algorithm>
#include "ComplexSorting.h"

bool Person::operator==(const Person &p) const
{
    return (this->name == p.name) && (this->age == p.age);
}
bool Person::operator<(const Person &p) const
{
    return this->name < p.name ;
}
bool Person::operator>(const Person &p) const
{
    return this->name > p.name ;
}
ostream &operator<<(ostream &os, const Person &p)
{
    os << "name: " << p.name << " age: " << p.age;
    return os;
}
bool lesserAge(const Person &p1, const Person &p2)
{
    return p1.age < p2.age;
}

void testCase()
{
    std::cout << "this is the complexSorting test case..." << std::endl;
    Person p1("cat", 20);
    Person p2("dog", 30);
    Person p3("fish", 78);
    Person p4("pig", 73);
    vector<Person> vecPerson(1, Person("master", 15));
    vector<Person>::iterator piter = vecPerson.begin();
    for (; piter < vecPerson.end(); piter++)
    {
        std::cout << *piter << std::endl;
    }
    vecPerson.push_back(p1);
    vecPerson.push_back(p2);
    vecPerson.push_back(p3);
    vecPerson.push_back(p4);

    piter = vecPerson.begin();
    for (; piter < vecPerson.end(); piter++)
    {
        std::cout << *piter << std::endl;
    }
    //默認升序排列，因爲Person類中提供了<運算符號
    sort(vecPerson.begin(), vecPerson.end());
    
   //可以自定義排序的項
    sort(vecPerson.begin(), vecPerson.end(), lesserAge);
    std::cout<< "comlexSorting test is finish .... "<< endl;
}