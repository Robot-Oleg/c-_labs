#include "person.h"

Person::Person()
{

}

Person::Person(int id, QString name) : _id(id), _name(name) {}

int Person::GetId()
{
    return _id;
}

QString Person::GetName()
{
    return _name;
}

void Person::SetId(int id)
{
    _id = id;
}

void Person::SetName(QString name)
{
   _name = name;
}
