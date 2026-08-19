#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

template <class T>  class Array{
    private:
     T *arr;
     unsigned int n;

    public:
        //Default constructor
        Array()
        {
            arr = new T[0]();
            n = 0;
        }
        //Parameter constructor
        Array(unsigned int n)
        {
            this->arr = new T[n]();
            this->n = n;
        }
        //Copy constructor
        Array(const Array &copy)
        {
            this->arr = new T[copy.n];
            this->n = copy.n;
            for(unsigned int i = 0; i < n; i++)
            {
                this->arr[i] = copy.arr[i];
            }
        }
        //Destructor
        ~Array()
        {
            delete [] this->arr;
        }
        //Operator overloading
        Array &operator=(const Array &copy)
        {
            if(this == &copy)
            {
                return *this;
            }
            delete [] this->arr;
            this->arr = new T[copy.n];
            this->n = copy.n;
            for(unsigned int i = 0; i < n; i++)
            {
                this->arr[i] = copy.arr[i];
            }
            return *this;
        }
        
        //Const operator overloading
        T operator[](unsigned int i)const
        {
            if(i >= this->n)
            {
                throw (Array::OutOfRangeException());
            }
            return this->arr[i];
        }
        //Non-const operator overloading
        T &operator[](unsigned int i)
        {
            if(i >= this->n)
            {
                throw (Array::OutOfRangeException());
            }
            return this->arr[i];
        }
        
        class OutOfRangeException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return "Index out of range";
                }
        };
        // Return the size of the array
        unsigned int size() const
        {
            return this->n;
        }
};