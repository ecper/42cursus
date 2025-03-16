#include "Zombie.hpp"

Zombie *newZombie(std:: string name)
{
    Zombie *data = new Zombie(name);
    return (data);
}