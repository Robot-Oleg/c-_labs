#ifndef TREE_H
#define TREE_H

#include "node.h"
#include "node.cpp"
#include <QVector>

template<class T>
class Tree
{
protected:
    Node<T> *root;
    int _size;
public:
    Tree();
    void Insert(int key, T data);
    Node<T>* Delete(int key);
    void Balance(int low = 0, int high = -1, QVector<Node<T>> array = nullptr);
    void TraversInOrder(Node<T> *node = nullptr);
    void TraversPreOrder(Node<T> *node = nullptr);
    void TraversPostOrder(Node<T> *node = nullptr);
    void FromBinaryTreeToArray(QVector<Node<T>> &array = nullptr, Node<T> *node = nullptr);
    void FromArrayToBinaryTree(QVector<T> array);
    void DeleteTree(Node<T> *node);
    Node<T>* GetRoot();
    Node<T>* Search(int key);
    QList<Node<T>*> travers;
};

#endif // TREE_H
