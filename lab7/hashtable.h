#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QString>
#include "list.h"
#include "list.cpp"
#include "person.h"
#include "myexeption.h"
#include <QRandomGenerator>
#include <QMessageBox>

class HashTable
{
protected:
   int _size;
   List<Person> *_array = new List<Person> [10];
public:
    HashTable();
    List<Person> operator[] (int index);
    int Insert(int id, QString name);
    int CalculateHash(int id);
//    int CalculateHash2(int id);
    void Delete(int id);
    Person* Search(int id);
    int GetSize();


};

#endif // HASHTABLE_H
