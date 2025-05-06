#pragma once

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon& weapon;
		std::string name;
	public:
		HumanA(std::string nom, Weapon& arme);
		~HumanA() = default;
		void	attack(void);
};