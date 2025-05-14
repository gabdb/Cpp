#pragma once

#include <iostream>
#include <string>

/*
	fracBits = 8 ici. donc shift factor = 2⁸ == 256.
	Ça veut dire que pour représenter `1.5`, on store 384, pcq 1.5 * 2⁸ = 384.
	donc rawBits = 384 et fracBits = 8.
*/

class Fixed
{
    private:
        int					_rawBits;
        static const int	_fracBits;
    public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
};