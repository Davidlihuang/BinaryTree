#include "siglelinklist.h"


SingleList::SingleList() {
    head = new ListNode;
    length = 0;
}
SingleList::SingleList(const SingleList &List) {
   head = new ListNode;
   ListNode* r = head;
   ListNode* p = List.head->next;
   ListNode* newNode = nullptr;
   length = List.length;
   while (p)
   {
       
       newNode = new ListNode(p->data);
       newNode->next = r->next;
       r->next = newNode;
       r = newNode;
       
       //insertPost(p->data);
       p = p->next;       
   }
}

SingleList::Status SingleList::insert(int i, Elementype val)  {
    ListNode* p = head;
    int j =0 ;
    while (p && j < i-1) {
        p = p->next;
        j++;
    }
    if (!p || j > i-1) return Error;
    ListNode* newNode = new ListNode(val);
    newNode->next = p->next;
    p->next = newNode;
    length++;
    return OK;
}
SingleList::Status SingleList::remove(int i, Elementype &val) {
    if(head != nullptr) {
        ListNode* p = head;
        ListNode* q = nullptr;
        int j =0;
        while (p->next && j < i-1)
        {
            p = p->next;
            j++;
        }
        if(!p->next || j > i-1) return Error;
        q = p->next;
        p->next = q->next;
        val = q->data;
        delete q;
        length--;
        return OK;
    }
    return Error;
}
SingleList::Status SingleList::insertBefore(Elementype val) {
    Status st = OK;
    st = insert(1,val);
    return st;
}
SingleList::Status SingleList::insertPost(Elementype val) {
    Status st = OK;
    st = insert(length+1,val);
    return st;
}
SingleList::Status SingleList::removeFirst(Elementype &val) {
    Status st = OK;
    st = remove(1,val);
    return st;
}
SingleList::Status SingleList::removePost(Elementype &val) {
    Status st = OK;
    st = remove(length, val);
    return st;
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
SingleList::Status SingleList::clearList() {
    int val;
    for (int i = 0; i < length; i++)
    {
        removeFirst(val);
    }
    if (length == 0) {
        head->next = nullptr;
        return OK;
    } else {
        return Error;
    }
}
Elementype& SingleList::operator[](int i) {
    ListNode* p  = head->next;
    i = i + 1;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if( !p || j > i) return head->data;
    return p->data;
}
const Elementype& SingleList::operator[](int i) const {
    ListNode* p  = head->next;
    i = i + 1;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if( !p || j > i) return head->data;
    return p->data;
}

SingleList& SingleList::operator=(const SingleList& List) {
    ListNode* r = head;
    ListNode* p = List.head->next;
    ListNode* newNode = nullptr;
    length = List.length;
    while (p)
    {   
        newNode = new ListNode(p->data);
        newNode->next = r->next;
        r->next = newNode;
        r = newNode;
       
        //insertPost(p->data);
        p = p->next;       
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, SingleList& list) {
    ListNode* p = list.head;
    while(p->next) {
        p = p->next;
        os << p->data << " ";
    }
    return os;
}

SingleList::~SingleList() {
    int val;
    clearList();
     std::cout << "release"<< std::endl;
    if(head->next == nullptr) {
        delete head;
        head = nullptr;
        std::cout << "release list"<< std::endl;
    }
}