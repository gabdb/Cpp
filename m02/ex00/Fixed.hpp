#pragma once

#include <iostream>
#include <string>

class Fixed
{
    private:
        int					_value;
        static const int	_8bits;
    public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};