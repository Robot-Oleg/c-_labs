#include "myhashtable.h"

MyHashTable::MyHashTable()  {
}

int MyHashTable::MostRepKey()
{
    int arr[10] = {};
    int max = 0, index = 0;
    for (int i = 0; i < this->_size; i++) {
        if (_array[i].IsEmty()) continue;
        for (int j = 0; j < this->_array[i].GetSize(); j++){
            arr[_array[i][j]->GetId()]++;
        }
    }
    for (int i = 0; i < this->_size; i++) {
        if (max < arr[i]) {
            index = i;
            max = arr[i];
        }
    }
    return index;
}
