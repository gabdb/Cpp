#pragma once

#include <iostream>
#include <string>

/*
	en gros cv buger quand tu fais WrongAnimal *ptr = new Wrongcat();
	pcq sans virtual (pas de vtable) le compil.
	ne sait pas que *ptr est en réalité de type WrongCat
	donc va appeler le makeSound() de la Base class
	+ le destructeur de WrongCat sera pas appelé = cata
*/

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal& other);

		void		makeSound() const;
		std::string	getType() const;
};