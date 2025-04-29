#include "Zombie.hpp"

int main(void)
{
	int		N;
	Zombie	*horde;

	N = 5;
	horde = zombieHorde(N, "Zombyy");
	for (int i = 0; i < N, i++;)
		(horde + i)->announce();
	delete[] horde;
	return (0);
}
