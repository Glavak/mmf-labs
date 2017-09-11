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

    this->datalen = other.datalen;
    this->datasize = other.datasize;
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

mystring & mystring::operator+=(const mystring & other)
{
    if (datalen + other.datalen + 1 > datasize)
    {
        char * oldData = data;
        datasize = datalen + other.datalen + 1;
        data = new char[datasize];

        memcpy(data, oldData, datalen);

        delete[] oldData;
    }

    memcpy(data + datalen, other.data, other.datalen + 1);

    this->datalen += other.datalen;
    return *this;
}

// NOTE: этот оператор - НЕ является членом класса. По сути это просто функция (не метод), которая принимает
//       два объекта mystring и возвращает один
mystring operator+(const mystring & a, const mystring & b)
{
    mystring str(a);

    // NOTE: используем предыдущий оператор, чтобы не переписывать код
    str += b;

    return str;
}

char mystring::operator[](const std::size_t index) const
{
    std::cout << std::endl << "const char []" << std::endl;
    return data[index];
}

char & mystring::operator[](const std::size_t index)
{
    std::cout << std::endl << "char & []" << std::endl;
    return data[index];
}

