#include "mytree.h"


template<class T>
MyTree<T>::MyTree()
{
    _count = 0;
}

template<class T>
void MyTree<T>::NumberOfNodsInLeftTree(Node<T> *node)
{
   if (node == nullptr) {
       node = this->root->leftChild;
   }
   if (node->leftChild) NumberOfNodsInLeftTree(node->leftChild);
   _count++;
   if (node->rightChild) NumberOfNodsInLeftTree(node->rightChild);
}

template<class T>
void MyTree<T>::SetCount(int count)
{
    _count = count;
}

template<class T>
int MyTree<T>::GetCount()
{
    return _count;
}
