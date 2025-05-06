
#include "HumanA.hpp"

HumanA::HumanA(std::string nom, Weapon& arme) : name(nom), weapon(arme) {}

void    HumanA::attack(void)
{
    std::cout << this->name << " attack with their " << this->weapon.getType() << std::endl;
}
