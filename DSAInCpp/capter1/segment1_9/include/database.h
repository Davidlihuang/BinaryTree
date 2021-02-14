#ifndef  DATABASE_H_ 
#define DATABASE_H_
#include <iostream>
#include <fstream>


template<class T>
class Database {
public:
    Database();
    void run();
private:
    std::fstream database;
    char fName[20];
    std::ostream& print(std::ostream&);
    void add(T& );
    bool find(const T&);
    void modify(const T&);
    friend std::ostream& operator<<(std::ostream&os, Database& db) {
        return db.print(os);
    }

};

using namespace std;
template <class T>
Database<T>::Database()
{
}

template <class T>
void Database<T>::add(T &d)
{
    database.open(fName, ios::in | ios::out | ios::binary);
    database.seekp(0, ios::end);
    d.writeToFile(database);
    database.close();
}

template <class T>
bool Database<T>::find(const T &d)
{
    T tmp;
    database.open(fName, ios::in | ios::binary);
    while (!database.eof())
    {
        tmp.readFromFile(database);
        if (tmp == d)
        {
            database.close();
            return true;
        }
    }
    database.close();
    return false;
}

template <class T>
void Database<T>::modify(const T &d)
{
    T tmp;
    database.open(fName, ios::in | ios::out | ios::binary);
    while (!database.eof())
    {
        tmp.readFromFile(database);
        if (tmp == d)
        {
            cin >> tmp;
            database.seekp(-d.size(), ios::cur);
            tmp.writeToFile(database);
            database.close();
            return;
        }
    }
    database.close();
    cout << "The record to be modified is not in the database!" << endl;
}

template <class T>
ostream &Database<T>::print(ostream &os)
{
    T tmp;
    database.open(fName, ios::in | ios::binary);
    while (true)
    {
        tmp.readFromFile(database);
        if (database.eof())
        {
            break;
        }
        cout << tmp << endl;
    }
    database.close();
    return os;
}

template <class T>
void Database<T>::run()
{
    cout << "File name: ";
    cin >> fName;
    char option[5];
    T record;
    cout << "1, Add 2, Find 3, Modify 4, Exit" << endl;
    cout << "Enter an option: ";
    cin.getline(option, 4);
    while (cin.getline(option, 4))
    {
        if (*option == '1')
        {
            cin >> record;
            add(record);
        }
        else if (*option == '2')
        {
            record.readKey();
            cout << "The record is ";
            if (find(record) == false)
                cout << "not";
            cout << " in the database\n";
        }
        else if (*option == '3')
        {
            record.readKey();
            modify(record);
        }
        else if (*option == '4')
        {
            cout << "Wrong  option!";
        }
        else
        {
            return;
        }
        cout << *this;
        cout << "Enter an option";
    }
}
#endif