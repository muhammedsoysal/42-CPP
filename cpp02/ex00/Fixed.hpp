#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int fixPointValue;
	static const int fractionalBits = 8;

public:
//constructors
	Fixed();
	// copy constructor
	Fixed(const Fixed &fixed);
	// copy assignment operator
	Fixed &operator=(const Fixed &fixed);
	// destructor
	~Fixed();
	// getters and setters
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif