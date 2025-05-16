
#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed() : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    this->_rawBits = other._rawBits;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->_rawBits = other._rawBits;
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
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