#include "Zombie.hpp"

void    randomChump(std::string name)
{
	if (name.empty())
	{
		std::cerr << "Error: empty field for 'name'" << std::endl;
		return ;
	}

	Zombie newZombie(name);
	newZombie.announce();
}