
#include "Dog.hpp"
#include "Cat.hpp"

/*
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
*/

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== CREATING OBJECTS ===" << std::endl;

    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* i = new WrongCat();

    std::cout << "\n=== TESTING getType() ===" << std::endl;
    std::cout << "meta type: " << meta->getType() << std::endl;
    std::cout << "i type:    " << i->getType() << std::endl;

    std::cout << "\n=== TESTING makeSound() ===" << std::endl;
    meta->makeSound(); // should call WrongAnimal::makeSound()
    i->makeSound();    //  calls WrongAnimal::makeSound() instead of WrongCat's

    std::cout << "\n=== DELETING OBJECTS ===" << std::endl;
    delete meta; // fine
    delete i;    // only calls WrongAnimal's destructor — WrongCat's is skipped

    std::cout << "\n=== DONE ===" << std::endl;

    return 0;
}