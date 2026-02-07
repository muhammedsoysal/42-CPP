/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoysal <musoysal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:43:33 by musoysal          #+#    #+#             */
/*   Updated: 2026/01/28 19:42:49 by musoysal         ###   ########.fr       */
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
	// örnek : value = 3.14, fractionalBits = 8, 1 << fractionalBits = 256 -> 3.14 * 256 = 802.24 -> roundf(802.24) = 802
	// 1 <<8 = 256 -> 3.14 * 256 = 802.24 -> roundf(802.24) = 802
	this->fixPointValue = roundf(value * (1 << this->fractionalBits));
}

// Converter functions
int Fixed::toInt(void) const
{
	// örnek : point_value = 802, fractionalBits = 8, 1 << fractionalBits = 256 -> 802 >> 8 = 3
	// 802 >> 8 = 3 -> 3.0
	// 3.0
	return this->fixPointValue >> this->fractionalBits;
}
float Fixed::toFloat(void) const
{
	// örnek : point_value = 802, fractionalBits = 8, 1 << fractionalBits = 256 -> 802 / 256 = 3.1328125
	return static_cast<float>(this->fixPointValue) / (1 << this->fractionalBits); // 1 << this->fractionalBits = 256
}

//	Operator overloads
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