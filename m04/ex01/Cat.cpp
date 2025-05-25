
#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat default ctor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy ctor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat dtor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		//sufficient because there are no new
		//'Cat' specific variables
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "MIAOW MIAOW !" << std::endl;
}

std::string	Cat::getType() const
{
	return this->type;
}