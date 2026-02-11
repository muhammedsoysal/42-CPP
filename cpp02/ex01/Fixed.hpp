#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(const Fixed &copy);
	Fixed(int value);
	Fixed(float value);

	Fixed &operator=(const Fixed &copy);
	~Fixed(void);
	int getRawBits(void) const;
	void setRawBits(int raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int fixPointValue;
	static const int fractionalBits = 8;
};
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif