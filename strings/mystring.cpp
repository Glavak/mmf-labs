//
// Created by User on Sep 11, 17.
//

#include <cstring>
#include "mystring.h"

// Конструктор по умолчанию
mystring::mystring()
{
    data = new char[1];
    data[0] = '\0';
    datasize = 1;
    datalen = 0;
}

// Конструктор  с параметром char *
mystring::mystring(const char * str)
{
    unsigned int len = strlen(str);
    data = new char[len + 1];
    memcpy(data, str, len + 1);
    datasize = len + 1;
    datalen = len;
}

// Конструктор копирования
mystring::mystring(mystring const & other)
{
    delete[] data;
    data = new char[other.datasize];
    memcpy(data, other.data, other.datasize);
}

// Деструктор
mystring::~mystring()
{
    delete[] data;
}

// Оператор присваивания
mystring & mystring::operator=(const mystring & other)
{
    delete[] data;
    data = new char[other.datasize];
    memcpy(data, other.data, other.datasize);

    return *this;
}

// Оператор приведения к const char *
mystring::operator char *() const
{
    return data;
}

