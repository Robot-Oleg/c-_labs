#include "company.h"

Company::Company()
{

}

Company::Company(QString companyName, QString specialty, QString position, int salary, int vacationDays, int minAge, int maxAge, QString bachelorDegree)
{
    _companyName = companyName;
    _specialty = specialty;
    _position = position;
    _salary = salary;
    _vacationDays = vacationDays;
    _minAge = minAge;
    _maxAge = maxAge;
    _bachelorDegree = bachelorDegree;
}

QString Company::GetSpecilty()
{
    return _specialty;
}

QString Company::GetPosition()
{
    return _position;
}

int Company::GetSalary()
{
   return _salary;
}


int Company::GetMaxAge() {
    return _minAge;
}

int Company::GetMinAge() {
    return _maxAge;
}

int Company::GetVacationDays() {
    return _vacationDays;
}

QString Company::GetCompanyName() {
    return _companyName;
}

QString Company::GetBachelorDegree() {
    return _bachelorDegree;
}
