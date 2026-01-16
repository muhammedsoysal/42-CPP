#ifndef FIXED_HPP
#define FIXED_HPP

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
	// Destructor
	~Fixed(void);
	// Getters and setters
	int getRawBits(void) const;
	void setRawBits(int raw);
	// Methods
	float toFloat(void) const;
	int toInt(void) const;

private:
	int pointValue;
	static const int fractionalBits = 8;
};
// Operators
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif