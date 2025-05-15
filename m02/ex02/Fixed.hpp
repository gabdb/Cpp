#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int					_rawBits;  //raw value stockée comme un int
		static const int	_fracBits; //tjrs 8
	public:
		//CTORS && DESTR.
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int intValue);
		Fixed(const float floatValue);
		~Fixed();

		//assignment operator
		Fixed& operator=(const Fixed& other);

		//comparison
		bool	operator>(const Fixed& f);
		bool	operator<(const Fixed& f);
		bool	operator>=(const Fixed& f);
		bool	operator<=(const Fixed& f);
		bool	operator==(const Fixed& f);
		bool	operator!=(const Fixed& f);

		//arithmetic
		Fixed	operator+(const Fixed& f);
		Fixed	operator-(const Fixed& f);
		Fixed	operator*(const Fixed& f);
		Fixed	operator/(const Fixed& f);

		//increm. / decrem.

			//prefix ++x / --x
		Fixed&	operator++();
		Fixed&	operator--();

			//postfix x++ / x--
		Fixed	operator++(int);
		Fixed	operator--(int);

		//anciens 
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		int		toInt(void) const;
		float	toFloat(void) const;

		//statics

};

std::ostream&	operator<<(std::ostream& output, const Fixed& point);