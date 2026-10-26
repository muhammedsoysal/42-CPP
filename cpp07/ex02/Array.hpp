#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>
# include <exception>

template <class T> class Array
{
    
private:
    T               *arr;
    unsigned int    n;

public:
    // Default constructor
    Array()
    {
        this->arr = new T[0]();
        this->n = 0;
    }

    // Parameter constructor
    Array(unsigned int n)
    {
        this->arr = new T[n]();
        this->n = n;
    }

    // Copy constructor
    Array(const Array &copy)
    {
        this->n = copy.n;
        this->arr = new T[copy.n]();
        for (unsigned int i = 0; i < this->n; i++)
        {
            this->arr[i] = copy.arr[i];
        }
    }

    // Destructor
    ~Array()
    {
        delete [] this->arr;
    }

    // Operator= overloading
    Array &operator=(const Array &copy)
    {
        if (this == &copy)
        {
            return *this;
        }
        delete [] this->arr;
        this->n = copy.n;
        this->arr = new T[copy.n]();
        for (unsigned int i = 0; i < this->n; i++)
        {
            this->arr[i] = copy.arr[i];
        }
        return *this;
    }

    // Const operator[] overloading
    const T &operator[](unsigned int i) const
    {
        if (i >= this->n)
        {
            throw (Array::OutOfRangeException());
        }
        return this->arr[i];
    }

    // Non-const operator[] overloading
    T &operator[](unsigned int i)
    {
        if (i >= this->n)
        {
            throw (Array::OutOfRangeException());
        }
        return this->arr[i];
    }

    // Exception class
    class OutOfRangeException : public std::exception
    {
    public:
        virtual const char *what() const throw()
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

#endif