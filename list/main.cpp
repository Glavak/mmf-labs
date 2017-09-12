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

    // На пятёрку:
    {
        mylist<int> sequence;

        sequence.push_back(4);
        sequence.push_back(8);
        sequence.push_back(9);
        sequence.push_back(16);
        sequence.push_back(17);
        sequence.push_back(42);

        std::cout << "Expected '9 17': ";
        for (mylist<int>::iterator i = sequence.begin(); i != sequence.end(); ++i)
        {
            if (*i % 2 == 1)
            {
                std::cout << *i << " ";

                // NOTE: так как из оператора * мы вернули ссылку на элемент (TElement &), то тут можем спокойно
                //       изменять значение в списке
                *i += 6;
            }
        }
        std::cout << std::endl;

        std::cout << "Expected '4 8 15 16 23 42': ";
        // А в новом C++ (ну как в новом, начиная с C++11) теперь, когда мы написали итератор, можно делать вот так:
        for (int & i : sequence)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}