
#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed() : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    this->_rawBits = other.getRawBits();
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->_rawBits = other.getRawBits();
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->_rawBits);
}

void Fixed::setRawBits(const int raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_rawBits = raw;
}

Fixed::Fixed(const int intValue) : _rawBits(intValue << _fracBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue) : _rawBits(static_cast<int> (roundf(floatValue * (1 << _fracBits))))
{
    std::cout << "Float constructor called" << std::endl;
}

int Fixed::toInt(void) const
{
    return (this->_rawBits >> _fracBits);
}

float Fixed::toFloat(void) const
{
    return (this->_rawBits / static_cast<float>(1 << _fracBits));
}

std::ostream& operator<<(std::ostream& output, const Fixed& point)
{
    output << point.toFloat();
    return (output);
}

bool    Fixed::operator>(const Fixed& f) const
{
    return (this->_rawBits > f._rawBits);
}

bool    Fixed::operator<(const Fixed& f) const
{
    return (this->_rawBits < f._rawBits);
}

bool    Fixed::operator>=(const Fixed& f) const
{
    return (this->_rawBits >= f._rawBits);
}

bool    Fixed::operator<=(const Fixed& f) const
{
    return (this->_rawBits <= f._rawBits);
}

bool    Fixed::operator==(const Fixed& f) const
{
    return (this->_rawBits == f._rawBits);
}

bool    Fixed::operator!=(const Fixed& f) const
{
    return (this->_rawBits != f._rawBits);
}

Fixed	Fixed::operator+(const Fixed& f) const
{
	return Fixed(this->toFloat() + f.toFloat());
}

Fixed	Fixed::operator-(const Fixed& f) const
{
	return Fixed(this->toFloat() - f.toFloat());
}

Fixed	Fixed::operator*(const Fixed& f) const
{
	return Fixed(this->toFloat() * f.toFloat());
}

Fixed	Fixed::operator/(const Fixed& f) const
{
	return Fixed(this->toFloat() / f.toFloat());
}

Fixed& Fixed::operator++(void)
{
    _rawBits += 1;
    return *this;
}

Fixed& Fixed::operator--(void)
{
    _rawBits -= 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed old(*this);
    _rawBits += 1;
    return old;
}

Fixed Fixed::operator--(int)
{
    Fixed old(*this);
    _rawBits -= 1;
    return old;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
	return f1._rawBits <= f2._rawBits ? f1 : f2;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
	return f1._rawBits <= f2._rawBits ? f1 : f2;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
	return f1._rawBits >= f2._rawBits ? f1 : f2;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
	return f1._rawBits >= f2._rawBits ? f1 : f2;
}