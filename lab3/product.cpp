#include "product.h"

Product::Product()
{

}

Product::Product(QString name, int day, int month, int year, int number, int price)
{
    _name = name;
    _day = day;
    _month = month;
    _year = year;
    _number = number;
    _price = price;
}

QString Product::GetName()
{
    return _name;
}

QString Product::GetDate()
{
    return _date;
}

int Product::GetNumber()
{
    return _number;
}

int Product::GetPrice()
{
    return _price;
}

int Product::GetDay()
{
    return _day;
}

int Product::GetMonth()
{
    return _month;
}

int Product::GetYear()
{
    return _year;
}

int Product::GetDataInDays()
{
   return  _day+_month*31+_year*365;
}
