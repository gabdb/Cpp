
#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog default ctor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy ctor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog dtor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		//sufficient because there are no new
		//'Dog' specific variables
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "WOUAF WOUAF !" << std::endl;
}

std::string	Dog::getType() const
{
	return this->type;
}
