#include <iostream>
#include "mystring.h"

int main()
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

    return 0;
}