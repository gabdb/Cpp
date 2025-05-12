
#include "HumanB.hpp"

HumanB::HumanB(std::string nom) : name(nom), weapon(nullptr) {}

HumanB::HumanB(std::string nom, Weapon& arme) : name(nom), weapon(&arme) {}

void    HumanB::attack(void)
{
    if (this->weapon)
        std::cout << this->name << " attack with their " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " has no weapon !" << std::endl;
}

void    HumanB::setWeapon(Weapon& arme)
{
    this->weapon = &arme;
}