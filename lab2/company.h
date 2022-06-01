#ifndef COMPANY_H
#define COMPANY_H
#include <QString>

class Company
{
private:
    QString _companyName,
            _specialty,
            _position,
            _bachelorDegree;
    int _salary,
        _vacationDays,
        _minAge,
        _maxAge;

public:
    Company();
    Company(QString companyName, QString specialty, QString position, int salary, int vacationDays, int minAge, int maxAge, QString bachelorDegree);
    QString GetCompanyName();
    QString GetSpecilty();
    QString GetPosition();
    QString GetBachelorDegree();
    int GetVacationDays();
    int GetMinAge();
    int GetMaxAge();
    int GetSalary();

};

#endif // COMPANY_H
