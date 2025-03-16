#include "Zombie.hpp"


void Zombie:: announce( void )
{
	std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie( std::string name )
{
	this->name = name;
}


Zombie::~Zombie()
{
	std::cout << this->name << ": " << "destroyed" << std::endl;
}
