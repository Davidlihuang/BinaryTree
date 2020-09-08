#ifndef SEQUENLIST_H_
#define SEQUENLIST_H_
#include <iostream>
typedef int ElemenType;
const int MAXSIZE = 1000;
class SequenList {
private:
    ElemenType* data;
    int length;
public:
    SequenList(int len) {
        if (len <= MAXSIZE) {

            data = new ElemenType[MAXSIZE];    
            length = len;
        } 
    }

    void addfirst(const ElemenType val);
    void addtail(const ElemenType val);
    void insert(int i, const ElemenType val);

    void removeFirst(ElemenType& val);
    void removeTail(ElemenType& val);
    void remove(int i, ElemenType& val);

    ElemenType getElement(int i) const;
    int locatElement(ElemenType val);
    int listLength() const { return length; }
    ElemenType& operator[](int i);
    ElemenType operator[](int i) const;

};
#endif