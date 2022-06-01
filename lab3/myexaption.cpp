#include "myexaption.h"

MyExaption::MyExaption(const char * desc)
{
    _message = desc;
}

const char *MyExaption::what() const noexcept
{
    return _message;
}
