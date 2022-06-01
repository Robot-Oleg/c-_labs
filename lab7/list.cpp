#include "list.h"

template<class T>
List<T>::List()
{
    head = nullptr;
    tail = nullptr;
}


template<class T>
int List<T>::GetSize()
{
    return _size;
}

template<class T>
bool List<T>::IsEmty()
{
    if (GetSize() == 0) return true;
    return false;
}

template<class T>
void List<T>::PushBack(T value)
{
    _size++;
    Node<T> *tmp = new Node<T>;
    tmp->data = value;
    tmp->next = nullptr;
    if (head == nullptr) {
        head = tmp;
        tail = tmp;
        tmp = nullptr;
    }
    else {
        tail->next = tmp;
        tail = tmp;
    }
}


template<class T>
T* List<T>::operator [](int pos) {
    Node<T> *cur = new Node<T>;
    Node<T> *pre = new Node<T>;
    cur = head;
    for (int i = 0; i < pos; i++){
        pre = cur;
        cur = cur->next;
    }
    return &(cur->data);
}

template<class T>
void List<T>::PushFront(T value) {
    Node<T> *tmp = new Node<T>;
    tail->next = tmp;
    tmp->data = value;
    tmp->next = head;
    head = tmp;
}

template<class T>
void List<T>::Insert(int pos, T value)
{
    Node<T> *pre = new Node<T>;
    Node<T> *cur = new Node<T>;
    Node<T> *tmp = new Node<T>;
    cur = head;
    for (int i = 1; i < pos; i++) {
        pre = cur;
        cur=cur->next;
    }
    tmp->data = value;
    pre->next = tmp;
    tmp->next = cur;
}

template<class T>
void List<T>::DeleteFront()
{
    Node<T> *tmp = new Node<T>;
    tmp = head;
    head = head->next;
    delete tmp;

}

template<class T>
void List<T>::DeleteBack()
{
    Node<T> *cur = new Node<T>;
    Node<T> *pre = new Node<T>;
    cur = head;
    while (cur->next != nullptr) {
        pre = cur;
        cur = cur->next;
    }
    tail = pre;
    pre->next = nullptr;
    delete cur;
}

template<class T>
void List<T>::DeleteByIndex(int pos)
{
    Node<T> *cur = new Node<T>;
    Node<T> *pre = new Node<T>;
    cur = head;
    for (int i = 0; i < pos; i++){
        pre = cur;
        cur = cur->next;
    }
    pre->next = cur->next;
}


