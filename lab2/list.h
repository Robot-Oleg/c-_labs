#ifndef LIST_H
#define LIST_H


template<class T>
class List
{
private:
    T* _list;
    int _size;
public:
    List();
    List(int size);
    T operator [](int index);
    void pushBack(T item);
    void Delete(int index);
    int GetSize();
    ~List();
};

#endif // LIST_H
