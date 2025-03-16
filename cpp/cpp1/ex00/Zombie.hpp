#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{

	public:

		void announce( void );
		Zombie( std::string name );
		~Zombie();

	private:
	std::string name;
};

#endif /* ********************************************************** ZOMBIE_H */