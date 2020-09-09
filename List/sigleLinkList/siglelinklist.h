#ifndef SINGLELINKLIST_H_
#define SINGLELINKLIST_H_
#include <iostream>
#include <climits>
typedef int Elementype ;


class SingleList{
private:
    struct ListNode;
    struct ListNode {
        Elementype data;
        ListNode* next;
        ListNode(Elementype val = INT_MIN): data(val), next(nullptr){}
    };
    ListNode* head;
    int length;
public:
    enum Status{Error = 0, OK = 1, Warning = 2, OverLength = 3};  
    SingleList();
    SingleList(const SingleList &List);
    ~SingleList();
    Status insert(int i, Elementype val);  
    Status remove(int i, Elementype &val);
    Status insertBefore(Elementype val);
    Status insertPost(Elementype val);
    Status removeFirst(Elementype &val);
    Status removePost(Elementype &val);
    int locateElemt(Elementype val);
    Status getElemt(int i, Elementype& val);
    int listLength() const {return length;}
    Elementype& operator[](int i);
    const Elementype& operator[](int i) const;
    SingleList& operator=(const SingleList& list);
    Status clearList();
    friend std::ostream& operator<<(std::ostream& os, SingleList& List);
};

#endif  