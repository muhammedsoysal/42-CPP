#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : fixPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixPointValue = value << this->fractionalBits;
}

Fixed::Fixed(float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixPointValue = static_cast<int>(roundf(value * (1 << this->fractionalBits)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
	//std::cout << "getRawBits member function called" << std::endl;
	return this->fixPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->fixPointValue = raw;
}

float Fixed::toFloat(void) const
{
	// exp: 1 << this->fractionalBits = 2^8 = 256
	return static_cast<float>(this->fixPointValue) / (1 << this->fractionalBits);
}

int Fixed::toInt(void) const
{
	// exp: pointValue 512
	//  512 >> 8 = 2
	return this->fixPointValue >> this->fractionalBits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}