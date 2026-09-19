#include "Span.hpp"

Span::Span()
{
    size = 0;
}

Span::Span(unsigned int N)
{
    size = N;
}

Span::Span(const Span &other)
{
    this->size = other.size;
    this->numbers = other.numbers;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->size = other.size;
        this->numbers = other.numbers;
    }
    return *this;
}

Span::~Span()
{
    numbers.clear();
}

void Span::addNumber(int num)
{
    if(this-> numbers.size() == this->size)
    {
        throw std::runtime_error("Span is full");
    }
    this-> numbers.push_back(num);
}
int Span::longestSpan() {
    if(this->numbers.size() <= 1)
        throw std::runtime_error("Span has less than 2 numbers");

    std::vector<int> sorted = this->numbers;
    std::sort(sorted.begin(), sorted.end());
    return sorted.back() - sorted.front();
}
int Span::shortestSpan() {
    if (this->numbers.size() < 2)
        throw std::runtime_error("Span has less than 2 numbers");
    std::vector<int> sorted = this->numbers;
    std::sort(sorted.begin(), sorted.end());
    int minDiff = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; i++) {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < minDiff)
            minDiff = diff;
    }
    return minDiff;
}