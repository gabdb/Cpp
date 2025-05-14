#pragma once

#include <iostream>
#include <string>


class Fixed
{
    private:
        int					_rawBits;  //raw value stockée comme un int
        static const int	_fracBits; //tjrs 8
    public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int intValue);
		Fixed(const float floatValue);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		int		toInt(void);
		float	toFloat(void);
};
std::ofstream&	operator<<(std::ofstream& output, Fixed& point);