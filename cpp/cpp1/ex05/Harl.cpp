#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug( void )
{
	std::cout	<< "DEBUG level:\n"
				<< "I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
				<< "I really do!" << std::endl;
}

void Harl::info( void )
{
		std::cout	<< "INFO level:\n"
				<< "I cannot believe adding extra bacon costs more money.\n"
				<< "You didn’t put enough bacon in my burger!\n"
				<< "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
		std::cout	<< "WARNING level:\n"
				<< "I think I deserve to have some extra bacon for free.\n"
				<< "I’ve been coming for years whereas you started working "
				<< "here since last month." << std::endl;
}

void Harl::error( void )
{
		std::cout	<< "ERROR level:\n"
				<< "This is unacceptable! I want to speak to the manager now."
				<< std::endl;
}

void Harl::complain( std::string level )
{
	std::string const level_switch[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (level == level_switch[i])
			(this->*f[i])();
	}
}
