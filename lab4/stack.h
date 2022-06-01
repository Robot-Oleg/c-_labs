#ifndef STACK_H
#define STACK_H


template<class T>
struct Node {
    T data;
    Node *next;
};

template<class T>
class Stack
{
private:
    Node<T> *top;
public:
    Stack();
    void Push(T value);
    T Pop();
    bool IsEmpty();
    T Top();
};

#endif // STACK_H
