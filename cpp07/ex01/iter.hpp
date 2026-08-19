#pragma once

#include <iostream>

template <typename T, typename F> void iter(T *t, int size, F f)
{
    int i = 0;
    while(i < size)
    {
        f(t[i]);
        i++;
    }
}

template <typename T> void print(T t)
{
    std::cout << t << std::endl; 
}
