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

#endif