#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cerr << "Error: invalid number zombies !" << std::endl;
		return nullptr;
	}
	if (name.empty())
	{
		std::cerr << "Error: empty name string !" << std::endl;
		return nullptr;
	}
	Zombie *horde = new Zombie[N];
	Zombie temp(name);
	for (int i = 0; i < N; i++)
	{
		horde[i] = temp;
		(horde + i)->announce();
	}
	std::cout << "\ndestruction of stack_alloc 'temp': ";
	return (horde);
}