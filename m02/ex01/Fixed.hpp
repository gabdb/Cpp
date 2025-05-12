#pragma once

#include <iostream>
#include <string>

class Fixed
{
    private:
        int					_rawBits;
        static const int	_8bits;
    public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
};