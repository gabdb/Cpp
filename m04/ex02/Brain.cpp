
#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "this idea is empty";
	std::cout << "Brain default ctor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	std::cout << "Brain copy ctor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain dtor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

void	Brain::setIdea(int index, std::string str)
{
	if (index >= 100 || index < 0)
		std::cout << "incorrect index !" << std::endl;
	else
	{
		this->ideas[index] = str;
		std::cout << "idea set succesfully" << std::endl;
	}
}

std::string Brain::getIdea(int index) const
{
	if (index >= 100 || index < 0)
	{
		std::cout << "incorrect index, returning NULL" << std::endl;
		return ("");
	}
	return (this->ideas[index]);
}