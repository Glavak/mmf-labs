//
// Created by Glavak on Sep 11, 17.
//

#ifndef STRINGS_MYSTRING_H
#define STRINGS_MYSTRING_H

#include <iostream>

class mystring
{
public:
    mystring();

    explicit mystring(const char * str);

    mystring(mystring const & other);

    ~mystring();

    mystring & operator=(const mystring & other);

    // NOTE: слово explicit тут (и выше в конструкторе) нужно, чтобы запретить случайно написать
    //          mystring str();
    //          char * ch = str
    //       возможно иногда так писать даже удобно, но такое неявное(implicit) преобразование типов может сильно
    //       запутать код и вызвать неоднозначности, и его лучше избегать
    explicit operator char *() const;

    mystring & operator+=(const mystring & other);

    // NOTE: этот оператор - НЕ является членом класса. По сути это просто функция (не метод), которая принимает
    //       два объекта mystring и возвращает один. Она объявлена здесь только ради ключевого слова friend, которое
    //       даёт нам доступ к приватным членам класса внутри этой функции
    friend mystring operator+(const mystring & a, const mystring & b);

    char operator[](std::size_t index) const;

    char & operator[](std::size_t index);

private:
    char * data;
    unsigned int datasize, datalen;
};


#endif //STRINGS_MYSTRING_H
