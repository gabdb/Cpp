
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() //calls Base default ctor first
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default Constructor called" << std::endl;
}
//init. list pas autorisee pour les variables issues du Base

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap 'name' Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		this->ClapTrap::operator=(other);
	}
	std::cout << "ScapTrap copy-assignment operator called" << std::endl;
	return *this;
}

void	ScavTrap::attack(const std::string& target)
{
    if (this->_hitPoints == 0) {
        std::cout << "ScavTrap " << this->_name << " is dead, no attack" << std::endl;
        return;
    }
    if (this->_energyPoints == 0) {
        std::cout << "ScavTrap " << this->_name << " has 0 energy, no attack" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->_name << " attacks " << target
              << ", causing " << this->_attackDamage << " points of damage!" << std::endl;

    this->_energyPoints -= 1;
}
