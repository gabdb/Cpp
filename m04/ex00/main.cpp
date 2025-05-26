
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();

	delete meta;
	delete j;
	delete i;

    return 0;
}

/*
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();

	std::cout << "meta type: " << meta->getType() << std::endl;
	std::cout << "i type:    " << i->getType() << std::endl;

	meta->makeSound(); //should call WrongAnimal::makeSound()
	i->makeSound();    //calls WrongAnimal::makeSound() instead of WrongCat's

	delete meta;
	delete i;    // only calls WrongAnimal's destructor !

	return 0;
}
*/