
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"


int main()
{
	//Animal *animal = new Animal();
	Animal *animal = new Dog();
	Dog *dog = new Dog();
	Cat *cat =  new Cat();

    animal->makeSound();
    dog->makeSound();
    cat->makeSound();


	delete animal;
	delete dog;
	delete cat;

	return (0);
	
}
