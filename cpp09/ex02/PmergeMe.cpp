#include "PmergeMe.hpp"
#include <cstddef>
#include <utility>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <sys/time.h>
#include <algorithm>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    _vec = other._vec;
    _deq = other._deq;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return (*this);
}

int PmergeMe::jacobsthal(int n)
{
    if (n == 0) return (0);
    if (n == 1) return (1);
    return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

static double getTimeInMicroseconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000.0) + tv.tv_usec;
}

void PmergeMe::sort(int ac, char** av)
{
    if (ac < 2)
    {
        std::cerr << "Error: No elements provided." << std::endl;
        return;
    }

    _vec.clear();
    for (int i = 1; i < ac; i++)
    {
        std::stringstream ss(av[i]);
        long val;
        if (!(ss >> val) || !(ss.eof()) || val <= 0)
        {
            std::cerr << "Error: Invalid positive integer -> " << av[i] << std::endl;
            return;
        }
        _vec.push_back(static_cast<int>(val));
		_deq.push_back(static_cast<int>(val));
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    double startVec = getTimeInMicroseconds();
    sortContainer<std::vector<int>, std::vector<std::pair<int, int> > >(_vec);
    double endVec = getTimeInMicroseconds();
	double startDeq = getTimeInMicroseconds();
	sortContainer< std::deque<int>, std::deque<std::pair<int, int> > >(_deq);
	double endDeq = getTimeInMicroseconds();	

    std::cout << "After:  ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    double timeVec = endVec - startVec;
	double timeDeq = endDeq - startDeq;
    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " 
              << std::fixed << std::setprecision(5) << timeVec << " us" 
              << std::endl;

    std::cout << "Time to process a range of " << _deq.size() 
              << " elements with std::deque : " 
              << std::fixed << std::setprecision(5) << timeDeq << " us" 
              << std::endl;


}