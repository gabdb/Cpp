#include "Zombie.hpp"

int main(void)
{
    Zombie *heapZombie = newZombie("Heap_Zombie");
    randomChump("Stack_Zombie");

    delete heapZombie;
    return (0);
}