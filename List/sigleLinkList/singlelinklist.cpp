#include "siglelinklist.h"


SingleList::SingleList() {
    head = new ListNode;
    length = 0;
}
SingleList::SingleList(const SingleList &List) {
   
}
SingleList::Status inserBefor(Elementype val) {

}
SingleList::Status SingleList::inserPost(Elementype val) {

}
SingleList::Status SingleList::insert(int i, Elementype val)  {

}
SingleList::Status SingleList::remove(int i, Elementype &val) {

}
int SingleList::locateElemt(Elementype val) {
    ListNode* p = head->next;
    int j = 1;
    while (p) {
        if (p->data == val) {
            return j;
        }
        p = p->next;
        j++;
    }
    return -1;
}
SingleList::Status SingleList::getElemt(int i, Elementype& val) {
    ListNode* p  = head->next;
    int j = 1;
    if (i > length) return Error;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if( !p || j > i) return Error;
    val = p->data;
    return OK;
}
std::ostream& operator<<(std::ostream& os, SingleList& list) {
    SingleList::ListNode* p = list.head;
    while(p->next) {
        p = p->next;
        os << p->data << " ";
    }
    return os;
}