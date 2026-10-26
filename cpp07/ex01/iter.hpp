#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <cstddef>

template <typename T, typename F>
void iter(T *t, std::size_t size, F f)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        f(t[i]);
    }
}

template <typename T>
void print(const T &t)
{
    std::cout << t << std::endl;
}

#endif