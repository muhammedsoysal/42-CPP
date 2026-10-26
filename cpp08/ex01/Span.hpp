#pragma once

#include <vector>

class Span
{
    private:
        std::vector<int> numbers;
        unsigned int size;
    public:
        Span(); 
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();
        void addNumber(int num);
        template <typename T> void addNumber(T begin, T end)
        {
            while (begin != end)
            {
                addNumber(*begin);
                begin++;
            }
        }
        int shortestSpan();
        int longestSpan();
};