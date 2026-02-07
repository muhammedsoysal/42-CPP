
#ifndef FIXED_HPP
#define FIXED_HPP

#include <string.h>
#include <cmath>
#include <iostream>

class Fixed
{
public:
	// Constructors
	Fixed(void);
	Fixed(const Fixed &copy);
	Fixed(int value);
	Fixed(float value);

	// Operators
	Fixed &operator=(const Fixed &copy);

	bool operator>(const Fixed &fixed) const;
	bool operator>=(const Fixed &fixed) const;
	bool operator<(const Fixed &fixed) const;
	bool operator<=(const Fixed &fixed) const;
	bool operator==(const Fixed &fixed) const;
	bool operator!=(const Fixed &fixed) const;

	Fixed operator+(const Fixed &fixed) const;
	Fixed operator-(const Fixed &fixed) const;
	Fixed operator*(const Fixed &fixed) const;
	Fixed operator/(const Fixed &fixed) const;

	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);

	// Destructor
	~Fixed(void);

	static Fixed &min(Fixed &num1, Fixed &num2);
	static const Fixed &min(const Fixed &num1, const Fixed &num2);
	static Fixed &max(Fixed &num1, Fixed &num2);
	static const Fixed &max(const Fixed &num1, const Fixed &num2);

	// Methods
	float toFloat(void) const;
	int toInt(void) const;

private:
	int fixPointValue;
	static const int fractionalBits = 8;
};
// 	overloaded Operators
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif