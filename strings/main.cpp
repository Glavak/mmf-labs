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

        mystring str3 = str;
        std::cout << "Expected 'Test!': " << (char *) str3 << std::endl;

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
        mystring first("Cat!");
        first[2] = 'r';
        std::cout << "Expected 'Car!': " << (char *) first << std::endl;

        const mystring second("Aaargh!");
        char symbol = second[4];
        std::cout << "Expected 'g': " << symbol << std::endl;
    }

    return 0;
}