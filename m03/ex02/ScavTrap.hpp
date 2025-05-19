
#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
        ~ScavTrap();

        ScavTrap& operator=(const ScavTrap& other);

        void    attack(const std::string& target); //override (mm signature)
        void    guardGate();
};