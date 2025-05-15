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
		bool	operator>(const Fixed& f) const;
		bool	operator<(const Fixed& f) const;
		bool	operator>=(const Fixed& f) const;
		bool	operator<=(const Fixed& f) const;
		bool	operator==(const Fixed& f) const;
		bool	operator!=(const Fixed& f) const;

		//arithmetic
		Fixed	operator+(const Fixed& f) const;
		Fixed	operator-(const Fixed& f) const;
		Fixed	operator*(const Fixed& f) const;
		Fixed	operator/(const Fixed& f) const;

		//increm. / decrem.

			//prefix ++x / --x
		Fixed&	operator++(void);
		Fixed&	operator--(void);

			//postfix x++ / x--
		Fixed	operator++(int);
		Fixed	operator--(int);

		//anciens 
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		int		toInt(void) const;
		float	toFloat(void) const;

		//static min/max'es
		static Fixed&		min(Fixed& f1, Fixed& f2);
		static const Fixed&	min(const Fixed& f1, const Fixed& f2);

		static Fixed&		max(Fixed& f1, Fixed& f2);
		static const Fixed&	max(const Fixed& f1, const Fixed& f2);
};

std::ostream&	operator<<(std::ostream& output, const Fixed& point);