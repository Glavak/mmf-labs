//
// Created by User on Sep 11, 17.
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

    explicit operator char *() const;

    mystring & operator+=(const mystring & other);

    friend mystring operator+(const mystring & a, const mystring & b);

    char operator[](std::size_t index) const;

    char & operator[](std::size_t index);

private:
    char * data;
    unsigned int datasize, datalen;
};


#endif //STRINGS_MYSTRING_H
