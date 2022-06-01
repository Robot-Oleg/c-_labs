#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include "hashtable.h"

class MyHashTable : public HashTable
{
public:
    MyHashTable();
    int MostRepKey();
};

#endif // MYHASHTABLE_H
