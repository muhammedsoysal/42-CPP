#include <iostream>
#include <string>
#include "iter.hpp"

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    ::iter(intArr, 5, print<int>);
    std::cout << std::endl;

    double doubleArr[] = {1.1, 2.2, 3.3, 4.4};
    ::iter(doubleArr, 4, print<double>);
    std::cout << std::endl;

    char charArr[] = {'s', 'o', 'y', 's', 'a', 'l'};
    ::iter(charArr, 6, print<char>);
    std::cout << std::endl;

    std::string strArr[] = {"Hello", "42", "World"};
    ::iter(strArr, 3, print<std::string>);

    return 0;
}
