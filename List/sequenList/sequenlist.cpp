#include "sequenlist.h"

void SequenList::addfirst(const ElemenType val) {

}
void SequenList::addtail(const ElemenType val) {

}
void SequenList::insert(int i, const ElemenType val) {
    if (i > 1 && i<length) {
        
    }
}

void SequenList::removeFirst(ElemenType& val) {

}
void SequenList::removeTail(ElemenType& val) {

}
void SequenList::remove(int i, ElemenType& val) {
    if (i < 0 && i>length) {
        return ;
    } 
    val = data[i-1];
    if (i < length) {
        for(int j=i-1; j< length-1; j++) {
        data[j] = data[j+1];
        }    
    }
    length --;
}
ElemenType SequenList::getElement(int i) const {
    if (i > 0 && i <= length) {
        return data[i-1];
    } else {
        return 0;
    }
}

ElemenType& SequenList::operator[](int i) {
    return data[i-1];
}
ElemenType SequenList::operator[](int i) const {
    return data[i-1];
}