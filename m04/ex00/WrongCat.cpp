
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "WrongCat default ctor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy ctor called" << std::endl;
}

WrongCat::~WrongCat() //won't be called without virtual in Base dtor
{
    std::cout << "WrongCat dtor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat assignment operator called" << std::endl;
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow Meow from WrongCat" << std::endl;
	//won't be called if trough an Animal* 
}

std::string WrongCat::getType() const
{
	return this->type;
	//same as previous function
}