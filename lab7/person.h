#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person
{
private:
    int _id;
    QString _name;
public:
    Person();
    Person(int id, QString name);
    int GetId();
    QString GetName();
    void SetId(int id);
    void SetName(QString name);
};

#endif // PERSON_H
