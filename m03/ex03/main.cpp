
#include "FragTrap.hpp"

int main(void)
{
    FragTrap a;
    FragTrap b("Tester");
    FragTrap c(b);
    FragTrap d = c;

    a.attack("Tester");
    b.beRepaired(10);
    a.takeDamage(15);
    c.attack("Someone");
    d.highFivesGuys();

    return 0;
}