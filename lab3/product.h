#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>

class Product
{
private:
    QString _name,
            _date;
    int _number,
        _price,
        _day,
        _month,
        _year;
public:
    Product();
    Product(QString name, int day, int month, int year, int number, int price);
    QString GetName();
    QString GetDate();
    int GetNumber();
    int GetPrice();
    int GetDay();
    int GetMonth();
    int GetYear();
    int GetDataInDays();
};

#endif // PRODUCT_H
