
#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default ctor called" << std::endl;
	this->_brain = new Brain();
	this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy ctor called" << std::endl;
	this->_brain = new Brain(*other._brain);}

Dog::~Dog()
{
	std::cout << "Dog dtor called" << std::endl;
	delete (this->_brain);
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		for (int i = 0; i < 100; i++)
			this->_brain->setIdea(i, other._brain->getIdea(i));
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

void	Dog::setIdea(int index, std::string str)
{
	this->_brain->setIdea(index, str);
}

std::string	Dog::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}