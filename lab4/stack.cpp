#include "stack.h"

template<class T>
Stack<T>::Stack()
{
    top = nullptr;
}

template<class T>
void Stack<T>::Push(T value)
{
   Node<T> *tmp = new Node<T>();
   tmp->data = value;
   tmp->next = top;
   top = tmp;
}

template<class T>
T Stack<T>::Pop()
{
    Node<T> *tmp = new Node<T>();
    tmp = top;
    top = tmp->next;
    T data = tmp->data;
    delete tmp;
    return data;
}

template<class T>
bool Stack<T>::IsEmpty()
{
    if (top == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

template<class T>
T Stack<T>::Top()
{
    return top->data;
}
