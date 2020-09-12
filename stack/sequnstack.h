#ifndef SEQUENSTACKFILE_H_
#define SEQUENSTACKFILE_H_

template <class T>
class SequenStack{
private:
    T* data;
    int top;
    int length;
public:
    enum Status {Error, OK, Warning};
    SequenStack();
    SequenStack(const SequenStack<T>& sstack);
    Status push(T val);
    T pop();
    T getTop() const {return data[top-1];}
    int size() const {return length;}
    int isEmpty() const {return top == 0;}
};
#endif