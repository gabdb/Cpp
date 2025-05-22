
#include "Animal.hpp"

Animal::Animal() : type("Undefined")
{
	std::cout << "Animal default ctor called" << std::endl;
}
Animal::Animal(const Animal& other)
{
	type = other.type;
	std::cout << "Animal copy ctor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal dtor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Animal assignment operator called" << std::endl;
	return *this;
}

void	Animal::makeSound() const
{
	std::cout << "generic Animal sound..." << std::endl;
}

std::string	Animal::getType() const
{
	return this->type;
}