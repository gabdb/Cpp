
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "'name' Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
 : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "Copy Constructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy operator called" << std::endl;

	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap" << this->_name << " is dead, no attack" << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap" << this->_name << " has 0 energy, no attack" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap" << this->_name << " is already dead..." << std::endl;
		return;
	}
	if (amount >= this->_hitPoints)
	{
		std::cout << "ClapTrap " << this->_name << " has taken " << amount
			<< " of damage and died" << std::endl;
		this->_hitPoints = 0;
		return;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " has been damaged by " 
					<< amount << " hit points" << std::endl;
		this->_hitPoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0){
		std::cout << "ClapTrap " << this->_name << " is already dead..." << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << this->_name << " has no energy point left, can't repair" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " has been repaired by " 
				<< amount << " hit points" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints--;
}