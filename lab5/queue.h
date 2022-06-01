#ifndef QUEUE_H
#define QUEUE_H

template<class T>
struct Node {
   T data;
   Node *next;
   Node *prev;
};

template<class T>
class Queue
{
private:
    Node<T> *begin, *end;
    int _size;
public:
    Queue();
    void Push(T item);
    T Pop();
    int GetSize();
    bool IsEmpty();
    T Start();
    T End();
};

#endif // QUEUE_H
