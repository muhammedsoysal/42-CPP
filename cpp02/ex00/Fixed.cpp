#include "Fixed.hpp"

Fixed::Fixed() : fixPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixPointValue = fixed.getRawBits();
}
Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->fixPointValue = fixed.getRawBits();
	return *this;
}
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixPointValue;
}
void Fixed::setRawBits(int const raw)
{
	this->fixPointValue = raw;
}