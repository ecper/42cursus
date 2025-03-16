#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name );

int main()
{
    int n = 10;
    Zombie *zombies = zombieHorde(n, "Foo");

    for (int i = 0; i < n; i++)
        zombies[i].announce();

    delete []zombies;
}