#include "hashtable.h"

HashTable::HashTable()
{
    _size = 10;
}

List<Person> HashTable::operator[](int index)
{
    return _array[index];
}

int HashTable::Insert(int id, QString name)
{
    int index = CalculateHash(id);
    Person person(id, name);
    _array[index].PushBack(person);
    return index;
}

int HashTable::CalculateHash(int id)
{
    return id % _size;
}

void HashTable::Delete(int id)
{
     delete Search(id);
}

Person* HashTable::Search(int id)
{
    int index = CalculateHash(id);
    if (_array[index].GetSize() == 0) {
        return nullptr;
    }
    else {
        Person *person = nullptr;
        for (int i = 0; i < _array[index].GetSize(); i++){
            if (_array[index][i]->GetId() == id) person = _array[index][i];
        }
        return person;
    }
}

int HashTable::GetSize()
{
    return _size;
}
