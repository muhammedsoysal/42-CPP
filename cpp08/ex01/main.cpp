#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);   

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "--------------------" << std::endl;

    Span bigSpan(10000);
    std::vector<int> bigVec;
    for (int i = -5000; i < 5000; i++)
        bigVec.push_back(i * -3);

    try 
    {
        bigSpan.addNumber(bigVec.begin(), bigVec.end());
        std::cout << bigSpan.shortestSpan() << std::endl;
        std::cout << bigSpan.longestSpan() << std::endl;

        bigSpan.addNumber(42);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
