#ifndef MYEXAPTION_H
#define MYEXAPTION_H

#include <QException>
#include <QtConcurrent/QtConcurrent>
#include <QMessageBox>

class MyExaption : public std::exception
{
public:
    MyExaption(const char *desc);
    const char *what() const _GLIBCXX_USE_NOEXCEPT;
private:
    const char * _message;
};

#endif // MYEXAPTION_H
