#include "tree.h"
#include <QDebug>



template<class T>
Tree<T>::Tree()
{
    root = nullptr;
    _size = 0;
}

template<class T>
void Tree<T>::Insert(int key, T data)
{
    Node<T> *x = root, *y = nullptr;
    while (x != nullptr) {
        y = x;

        if (key < x->_key) x = x->leftChild;
        else if (key > x->_key) x = x->rightChild;
    }

    Node<T> *newNode = new Node<T>(key, data);
    if (y == nullptr) root = newNode;
    else {
        if (key < y->_key) y->leftChild = newNode;
        else if (key > y->_key) y->rightChild = newNode;
        newNode->parrent = y;
    }
    _size++;
//    Node<T> *x = Search(key);
//    Node<T> *newNode = new Node<T>(key, data);
//    if (x == nullptr) root = newNode;
//    else {
//        if (key < x->_key) x->leftChild = newNode;
//        else if (key > x->_key) x->rightChild = newNode;
//        newNode->parrent = x;
//    }

}

template<class T>
Node<T>* Tree<T>::Delete(int key)
{
   int saveKey = 0;
    T param;
    Node<T> *node = Search(key);
    Node<T> *prev = node->parrent;

    if (node == nullptr) return node;

    if (node->leftChild == nullptr && node->rightChild == nullptr) {
        if(prev == nullptr)
        {
//            root = node;
            delete root;
            root = nullptr;
            _size--;
            return node;
        }
        if(prev->_key > node->_key) {
            prev->leftChild = nullptr;
        }
        else {
            prev->rightChild = nullptr;
        }

        delete node;
        _size--;
        node = nullptr;

    }

    else if(node->leftChild == nullptr)
        {
           if(prev == nullptr)
            {
                root = node->rightChild;
            }
            else
            {
                if(prev->_key > node->_key)
                {
                    prev->leftChild = node->rightChild;
                }
                else
                {
                    prev->rightChild = node->rightChild;
                }
            }
            delete node;
            _size--;
            node = nullptr;
        }
        else if(node->rightChild == nullptr)
        {
           if(prev == nullptr)
            {
                root = node->rightChild;
            }
            else
            {
                if(prev->_key > node->_key)
                {
                    prev->leftChild = node->leftChild;
                }
                else
                {
                    prev->rightChild = node->leftChild;
                }
            }

            delete node;
            _size--;
            node = nullptr;
        }
        else
        {
            Node<T> *octa = node->rightChild;
             saveKey = octa->_key;
              param  = octa->_data;
             while(octa->leftChild != nullptr )
             {
                 octa = octa->leftChild;
                 saveKey = octa->_key;
                  param  = octa->_data;
             }
             octa = Delete(saveKey);
             node->_key = saveKey;
             node->_data = param;
            if(prev == nullptr)
             {
                 root = node;
             }

        }
    return node;
}

template<class T>
void Tree<T>::Balance(int low, int high, QVector<Node<T>> array)
{

    if (high == -1) {
        high = array.size();
    }

    if (low == high) {
        return;
    }

    int mid = (low + high) >> 1;

    this->Insert(array[mid]._key, array[mid]._data);

    Balance(mid+1, high, array);
    Balance(low, mid, array);
}

template<class T>
void Tree<T>::FromBinaryTreeToArray(QVector<Node<T>> &array, Node<T> *node)
{
    if (!node) node = root;
    if (node->leftChild) FromBinaryTreeToArray(array, node->leftChild);
    array.append(*node);
    if (node->rightChild) FromBinaryTreeToArray(array, node->rightChild);

}

template<class T>
void Tree<T>::FromArrayToBinaryTree(QVector<T> array)
{
    foreach(T item, array) {
        this->Insert(item);
    }
}

template<class T>
void Tree<T>::DeleteTree(Node<T> *node)
{
    if (!node) return;
    if (node->leftChild) DeleteTree(node->leftChild);
    if (node->rightChild) DeleteTree(node->rightChild);
    this->Delete(node->_key);
}

template<class T>
Node<T>* Tree<T>::GetRoot()
{
    return root;
}

template<class T>
void Tree<T>::TraversInOrder(Node<T> *node)
{
    if (!node) {
        node = root;
        travers.clear();
    }
    if (node->leftChild) TraversInOrder(node->leftChild);
    travers.append(node);
    if (node->rightChild) TraversInOrder(node->rightChild);
}

template<class T>
void Tree<T>::TraversPreOrder(Node<T> *node)
{
    if (!node) {
        node = root;
        travers.clear();
    }
    travers.append(node);
    if (node->leftChild) TraversInOrder(node->leftChild);
    if (node->rightChild) TraversInOrder(node->rightChild);

}

template<class T>
void Tree<T>::TraversPostOrder(Node<T> *node)
{
     if (!node) {
        node = root;
        travers.clear();
    }
    if (node->leftChild) TraversInOrder(node->leftChild);
    if (node->rightChild) TraversInOrder(node->rightChild);
    travers.append(node);
}

template<class T>
Node<T>* Tree<T>::Search(int key)
{
    Node<T> *x = root;
    while (x != nullptr) {
        if (key == x->_key) return x;
        else {
            if (key < x->_key) x = x->leftChild;
            else if (key > x->_key) x = x->rightChild;
        }
    }
}

//template<class T>
//QList<T>* Tree<T>::GetTraversList()
//{
//    return travers;
//}

