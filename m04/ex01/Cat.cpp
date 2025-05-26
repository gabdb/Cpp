
#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default ctor called" << std::endl;
	this->_brain = new Brain();
	this->type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy ctor called" << std::endl;
	this->_brain = new Brain(*other._brain);
}

Cat::~Cat()
{
	std::cout << "Cat dtor called" << std::endl;
	delete (this->_brain);
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		for (int i = 0; i < 100; i++)
			this->_brain->setIdea(i, other._brain->getIdea(i));
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

void	Cat::setIdea(int index, std::string str)
{
	this->_brain->setIdea(index, str);
}

std::string	Cat::getIdea(int index)
{
	return (this->_brain->getIdea(index));
}