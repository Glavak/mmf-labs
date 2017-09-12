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

        std::cout << "Expected '2 3 5': "
                  << primes.pop() << " " << primes.pop() << " " << primes.pop() << std::endl;
    }

    // На четвёрку:
    {
        mylist<int> odds;

        odds.push_back(3);
        odds.push_back(5);
        odds.push_back(7);

        std::cout << "Expected '3 5 7': "
                  << odds.pop_back() << " " << odds.pop_back() << " " << odds.pop_back() << std::endl;

        mylist<int> other;
        // odds = other;  <--- это не скомпилируется, так как запрещён оператор присваивания
    }

    return 0;
}