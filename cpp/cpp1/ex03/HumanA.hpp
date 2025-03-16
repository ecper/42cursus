#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{

	public:

		HumanA(std::string name, Weapon new_weapon);
		~HumanA();
		void attack();

	private:
		Weapon weapon;
		std::string name;
};


#endif /* ********************************************************** HUMANA_H */