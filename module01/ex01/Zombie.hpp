#pragma once

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie() = default;
		Zombie(std::string name);
		~Zombie();
		void	announce( void );
};

Zombie* zombieHorde(int N, std::string name);