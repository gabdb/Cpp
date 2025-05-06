#include "Weapon.hpp"

Weapon::Weapon(std::string name) : type(name) {}

void    Weapon::setType(std::string name)
{
    this->type = name;
}

const std::string& Weapon::getType(void)
{
    return (this->type);
}
