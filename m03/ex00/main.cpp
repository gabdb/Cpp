
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap premier;
	ClapTrap second("Second");
	ClapTrap troisieme(second);

	premier.attack("Target");
    second.takeDamage(5);
    second.beRepaired(10);
	troisieme.attack("qqn");
    troisieme.takeDamage(15);

	return 0;
}