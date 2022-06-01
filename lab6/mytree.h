#ifndef MYTREE_H
#define MYTREE_H

#include "tree.h"
#include "node.h"

template <class T>
class MyTree : public Tree<T>
{

private:
//    Node<T> *root;
//    int _size;
    int _count;

public:
    MyTree();
    void NumberOfNodsInLeftTree(Node<T> *node = nullptr);
    void SetCount(int count);
    int GetCount();
};

#endif // MYTREE_H
