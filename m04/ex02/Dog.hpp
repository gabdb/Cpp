#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* _brain;
	public:
		Dog();
		Dog(const Dog& other);
		virtual ~Dog();
		Dog& operator=(const Dog& other);

		virtual void		makeSound() const;
		virtual std::string	getType() const;

		void		setIdea(int index, std::string str);
		std::string	getIdea(int index) const;
};