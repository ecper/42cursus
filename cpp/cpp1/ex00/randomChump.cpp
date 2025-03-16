#include "Zombie.hpp"

void randomChump(std:: string name)
{
    Zombie *data = new Zombie(name);
    data->announce();
    delete data;
}