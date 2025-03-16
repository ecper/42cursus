#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{

	public:

		void announce( void );
		void setName(std::string name );
		Zombie( std::string name );
		Zombie();
		~Zombie();

	private:
	std::string name;
};

#endif /* ********************************************************** ZOMBIE_H */