#include "queue.h"

template<class T>
Queue<T>::Queue()
{
    begin = nullptr;
    end = nullptr;
    _size = 0;
}

template<class T>
void Queue<T>::Push(T item)
{
   Node<T> *tmp = new Node<T>;
   tmp->data = item;
   if (!begin) {
       begin = tmp;
       end = tmp;
       tmp->next = nullptr;
       tmp->prev = nullptr;
   }
   else {
        end->prev = tmp;
        tmp->next = end;
        end = tmp;
   }
   _size++;
}

template<class T>
T Queue<T>::Pop()
{
    if (this->IsEmpty()) return nullptr;
    Node<T> *tmp = new Node<T>();
    tmp = begin;
    T data = tmp->data;
    begin = tmp->prev;
    delete tmp;
    return data;

}

template<class T>
int Queue<T>::GetSize()
{
    return _size;
}

template<class T>
bool Queue<T>::IsEmpty()
{
    if (begin == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

template<class T>
T Queue<T>::Start()
{
    return end->data;
}

template<class T>
T Queue<T>::End()
{
   return begin->data;
}
