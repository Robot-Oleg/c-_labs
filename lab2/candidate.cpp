#include "candidate.h"


Candidate::Candidate(QString name, QString dateOfBirth, QString specialty, QString positon, QString bachelorDegree, int minSalary)
{
    _name = name;
    _dateOfBirth = dateOfBirth;
    _specialty = specialty;
    _position = positon;
    _bachelorDegree = bachelorDegree;
    _minSalary = minSalary;
}

QString Candidate::GetName()
{
    return _name;
}

QString Candidate::GetDateOfBirth()
{
    return _dateOfBirth;
}

QString Candidate::GetSpecilty()
{
    return _specialty;
}

QString Candidate::GetPosition()
{
    return _position;
}

QString Candidate::GetBachelorDegree()
{
   return _bachelorDegree;
}

int Candidate::GetMinSalary()
{
    return _minSalary;
}

Candidate::Candidate(){

}
