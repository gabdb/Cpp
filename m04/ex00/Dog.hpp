#pragma once

#include "Animal.hpp"

/*
	virtual pas nécessaire pr ~Dog() et les 2 methods
	car automatiquement le cas ! (virtual inherited)
	mais good practice
*/

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& other);
		virtual ~Dog();
		Dog& operator=(const Dog& other);

		virtual void		makeSound() const;
		virtual std::string	getType() const;
};