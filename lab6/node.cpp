#include "node.h"


template<class T>
Node<T>::Node(int key, T data) : _key(key), _data(data)
{
    parrent = nullptr;
    leftChild = nullptr;
    rightChild = nullptr;
}
