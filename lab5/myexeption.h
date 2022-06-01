#ifndef MYEXEPTION_H
#define MYEXEPTION_H

#include <QException>
#include <QtConcurrent/QtConcurrent>
#include <QMessageBox>

class MyExeption : public std::exception
{
public:
    MyExeption(const char *desc);
    const char *what() const _GLIBCXX_USE_NOEXCEPT;
private:
    const char * _message;
};

#endif // MYEXEPTION_H
