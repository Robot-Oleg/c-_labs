#include "myexeption.h"

MyExeption::MyExeption(const char *desc){
    _message = desc;
}

const char *MyExeption::what() const noexcept
{
    return _message;
}
