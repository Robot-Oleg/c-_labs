#include "list.h"


template<class T>
List<T>::List()
{
   _size = 0;
   _list = new T[_size];
}

template<class T>
List<T>::List(int size)
{
   _size = size;
   _list = new T[_size];
}

template<class T>
T List<T>::operator [](int index)
{
        return _list[index];
}

template<class T>
void List<T>::pushBack(T item)
{
    T *_newList = new T[++_size];
    for (int i = 0; i < _size; i++){
        if(i != _size-1) {
            _newList[i] = _list[i];
        }
        else {
            _newList[i] = item;
            break;
        }
    }
    delete[] _list;
    _list = _newList;
}

template<class T>
void List<T>::Delete(int index)
{
    T *_newList = new T[_size-1];
    int j = 0;
    for (int i = 0; i < _size; i++){
        if(index == i) {
            continue;
        }
        else {
            _newList[j++] = _list[i];
        }
    }
    delete[] _list;
    _size--;
    _list = _newList;
}

template<class T>
int List<T>::GetSize()
{
    return _size;
}

template<class T>
List<T>::~List()
{
    delete [] _list;
}
