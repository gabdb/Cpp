
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap a;
    ScavTrap b("Random");
    ScavTrap c(b);

    ClapTrap d("Clap_alive");

    a.attack("Someone"); //function overriden, so 'a' and 'd' do not call the same function !
    d.attack("Someone as well");

    b.guardGate();

    c.takeDamage(15);
    c.beRepaired(10);

    return 0;
}