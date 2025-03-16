#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{

	public:
		Weapon(std::string type);
		Weapon();
		~Weapon();
		std::string getType();
		void setType(std::string new_type);


	private:
		std::string type;
};


#endif /* ********************************************************** WEAPON_H */