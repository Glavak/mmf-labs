#include <iostream>
#include "mystring.h"

int main()
{
    // На тройку:
    {
        mystring str("Test!");
        std::cout << "Expected 'Test!': " << (char *) str << std::endl;

        mystring str2;
        std::cout << "Expected empty string: " << (char *) str2 << std::endl;

        // NOTE: тут будет вызван конструктор копирования
        mystring str3 = str;
        std::cout << "Expected 'Test!': " << (char *) str3 << std::endl;

        // NOTE: а тут оператор присваивания
        str3 = str2;
        std::cout << "Expected empty string: " << (char *) str3 << std::endl;
    }

    // На четвёрку:
    {
        mystring first("Hello ");
        mystring second("world!");
        std::cout << "Expected 'Hello world!': " << (char *) (first + second) << std::endl;

        mystring result("Goodbye ");
        mystring addition("emptiness inside");
        result += addition;
        std::cout << "Expected 'Goodbye emptiness inside': " << (char *) result << std::endl;
    }

    // На пятёрку:
    {
        // NOTE: будет использоваться неконстантный оператор, так как объект first не объявлен как const
        mystring first("Cat!");
        first[2] = 'r';
        std::cout << "Expected 'Car!': " << (char *) first << std::endl;

        // NOTE: будет использоваться константный оператор, так как объект second объявлен как const
        const mystring second("Aaargh!");
        char symbol = second[4];
        std::cout << "Expected 'g': " << symbol << std::endl;
    }

    return 0;
}