
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"


int main() {
    std::cout << "=== Creating array of Animals ===" << std::endl;

    const int SIZE = 4;
    Animal* animals[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        if (i < 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n=== Testing makeSound() ===" << std::endl;
    for (int i = 0; i < SIZE; ++i)
        animals[i]->makeSound();

    std::cout << "\n=== Deleting array of Animals ===" << std::endl;
    for (int i = 0; i < SIZE; ++i)
        delete animals[i];  // calls Cat or Dog dtor, then Base dtor

    std::cout << "\n=== Deep Copy Test ===" << std::endl;

    Cat basic;
    basic.setIdea(0, "test chat");
    basic.setIdea(5, "deuxieme test");

    std::cout << "[Original] idea[0]: " << basic.getIdea(0) << std::endl;
    std::cout << "[Original] idea[5]: " << basic.getIdea(5) << std::endl;

    Cat copy(basic);  // Copy constructor
    std::cout << "[Copy]     idea[0]: " << copy.getIdea(0) << std::endl;

    // Change the copy
    copy.setIdea(0, "changement copie TEST");

    // Check if the original was affected
    std::cout << "\nAfter modifying the copy:" << std::endl;
    std::cout << "[Original] idea[0]: " << basic.getIdea(0) << std::endl;
    std::cout << "[Copy]     idea[0]: " << copy.getIdea(0) << std::endl;

    return 0;
}
