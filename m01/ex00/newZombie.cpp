#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    Zombie  *ptr;

    if (name.empty())
    {
        std::cerr << "Error: empty field for 'name'" << std::endl;
        return (nullptr);
    }
    ptr = new Zombie(name);
    ptr->announce();
    return (ptr);
}