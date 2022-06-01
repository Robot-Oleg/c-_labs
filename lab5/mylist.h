#ifndef MYLIST_H
#define MYLIST_H

#include "queue.h"

template<class T>
class MyList : public Queue<T>
{
private:
    Node<T> *begin, *end;
    int _size;
public:
    MyList();
    T GetByIndex(int index);
    void PushBack(T item);
    int GetSize();
};

#endif // MYLIST_H
