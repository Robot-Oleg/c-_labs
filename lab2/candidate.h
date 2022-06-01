#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <QString>

class Candidate
{
private:
    QString _name,
            _dateOfBirth,
            _specialty,
            _position,
            _bachelorDegree;
    int _minSalary;


public:
    Candidate();
    Candidate(QString name, QString dateOfBirth, QString specialty, QString positon, QString bachelorDegree, int minSalary);
    QString GetName();
    QString GetDateOfBirth();
    QString GetSpecilty();
    QString GetPosition();
    QString GetBachelorDegree();
    int GetMinSalary();
};

#endif // CANDIDATE_H
