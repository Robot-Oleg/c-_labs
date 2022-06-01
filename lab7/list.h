#ifndef LIST_H
#define LIST_H

#include <QString>

template <class T>
struct Node {
    T data;
    Node *next;
};

template <class T>
class List
{
private:
    Node<T> *head, *tail;
    int _size = 0;
public:
    List();
    T *operator [](int pos);
    void PushFront(T value);
    void PushBack(T value);
    void Insert(int pos, T value);
    void DeleteFront();
    void DeleteBack();
    void DeleteByIndex(int pos);
    int GetSize();
    bool IsEmty();
};

#endif // LIST_H



