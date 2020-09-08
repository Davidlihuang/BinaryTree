#ifndef SINGLELINKLIST_H_
#define SINGLELINKLIST_H_
#include <iostream>
#include <climits>
typedef int Elementype ;
class SingleList{
public:
    enum Status{Error = 0, OK = 1, Warning = 2, OverLength = 3};
private:
    struct ListNode {
        Elementype data;
        ListNode* next;
        ListNode(Elementype val = INT_MIN):data(val), next(nullptr){}
    };
    
public:
    SingleList();
    SingleList(const SingleList &List);
    Status inserBefor(Elementype val);
    Status inserPost(Elementype val);
    Status insert(int i, Elementype val);  
    Status remove(int i, Elementype &val);
    int locateElemt(Elementype val);
    Status getElemt(int i, Elementype& val);
    friend std::ostream& operator<<(std::ostream& os, SingleList& List);
private:
    ListNode* head;
    int length;
};

#endif  