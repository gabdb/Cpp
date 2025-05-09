#pragma once

#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon*		weapon;
        std::string	name;
	public:
		HumanB() = default;
		HumanB(std::string nom);
		HumanB(std::string nom, Weapon& arme);
		~HumanB() = default;
		void	setWeapon(Weapon& arme);
		void	attack(void);
};