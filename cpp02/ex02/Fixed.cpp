/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoysal <musoysal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:43:33 by musoysal          #+#    #+#             */
/*   Updated: 2026/02/11 12:28:37 by musoysal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : fixPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixPointValue = copy.fixPointValue;
}
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixPointValue = value << this->fractionalBits;
}
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixPointValue = static_cast<int>(roundf(value * (1 << this->fractionalBits)));
}

int Fixed::toInt(void) const
{
	return this->fixPointValue >> this->fractionalBits;
}
float Fixed::toFloat(void) const
{
	return static_cast<float>(this->fixPointValue) / (1 << this->fractionalBits);
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->fixPointValue = copy.fixPointValue;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
bool Fixed::operator>(const Fixed &fixed) const
{
	return this->fixPointValue > fixed.fixPointValue;
}
bool Fixed::operator>=(const Fixed &fixed) const
{
	return this->fixPointValue >= fixed.fixPointValue;
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return this->fixPointValue < fixed.fixPointValue;
}
bool Fixed::operator<=(const Fixed &fixed) const
{
	return this->fixPointValue <= fixed.fixPointValue;
}
bool Fixed::operator==(const Fixed &fixed) const
{
	return this->fixPointValue == fixed.fixPointValue;
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return this->fixPointValue != fixed.fixPointValue;
}
Fixed Fixed::operator*(const Fixed &fixed) const
{
	return Fixed(this->toFloat() * fixed.toFloat());
}
Fixed Fixed::operator/(const Fixed &fixed) const
{
	return Fixed(this->toFloat() / fixed.toFloat());
}
Fixed Fixed::operator+(const Fixed &fixed) const
{
	return Fixed(this->toFloat() + fixed.toFloat());
}
Fixed Fixed::operator-(const Fixed &fixed) const
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed &Fixed::operator++(void)
{
	++this->fixPointValue;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed f(*this);
	this->fixPointValue++;
	return f;
}
Fixed &Fixed::operator--(void)
{
	--this->fixPointValue;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed f(*this);
	this->fixPointValue--;
	return f;
}
Fixed &Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1 < num2)
		return num1;
	return num2;
}
Fixed &Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1 > num2)
		return num1;
	return num2;
}
const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2)
{
	if (num1 < num2)
		return num1;
	return num2;
}
const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2)
{
	if (num1 > num2)
		return num1;
	return num2;
}