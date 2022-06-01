#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
public:
    Node *rightChild;
    Node *leftChild;
    Node *parrent;
    T _data;
    int _key;
    Node(int key, T data);
};

#endif // NODE_H
