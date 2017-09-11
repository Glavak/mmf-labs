#include <iostream>
#include "mylist.h"

int main()
{
    // На тройку:
    {
        mylist<int> primes;

        primes.push(2);
        primes.push(3);
        primes.push(5);

        std::cout << "Expected '2 3 5': " << primes.pop() << " " << primes.pop() << " " << primes.pop() << std::endl;
    }

    return 0;
}