#include <iostream>
#include "mystring.h"

int main()
{
    // На тройку:
    {
        mystring str("Test!");
        char * raw = str;
        std::cout << "Expected 'Test!': " << raw << std::endl;

        mystring str2;
        char * raw2 = str2;
        std::cout << "Expected empty string: " << raw2 << std::endl;

        mystring str3 = str;
        char * raw3 = str3;
        std::cout << "Expected 'Test!': " << raw3 << std::endl;

        str3 = str2;
        char * raw4 = str3;
        std::cout << "Expected empty string: " << raw4 << std::endl;
    }

    // На четвёрку:
    {
        mystring first("Hello ");
        mystring second("world!");
        char * raw = first + second;

        std::cout << "Expected 'Hello world!': " << raw << std::endl;

        mystring result("Goodbye ");
        mystring addition("emptiness inside");
        result += addition;
        char * raw2 = result;

        std::cout << "Expected 'Goodbye emptiness inside': " << raw2 << std::endl;
    }

    return 0;
}