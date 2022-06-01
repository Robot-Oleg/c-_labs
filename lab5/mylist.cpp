#include "mylist.h"


template<class T>
MyList<T>::MyList()
{
    begin = nullptr;
    end = nullptr;
    _size = 0;
}

template<class T>
T MyList<T>::GetByIndex(int index)
{
   Node<T> *tmp = new Node<T>;
   if (begin != nullptr) {
       tmp = begin;
       for (int i = 0; i < index; i++) {
            tmp = tmp->next;
       }
       return tmp->data;
   }
}

template<class T>
void MyList<T>::PushBack(T item)
{
   Node<T> *tmp = new Node<T>;
   tmp->data = item;
   if (!begin) {
       begin = tmp;
       end = tmp;
       tmp->next = end;
       tmp->prev = begin;
   }
   else {
        end->next = tmp;
        tmp->prev = end;
        tmp->next = begin;
        end = tmp;
   }
   _size++;
}



template<class T>
int MyList<T>::GetSize()
{
    return _size;
}

