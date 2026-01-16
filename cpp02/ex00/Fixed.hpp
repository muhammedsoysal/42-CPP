#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int pointValue;
		static const int fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed &operator=(const Fixed &fixed);
        ~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif