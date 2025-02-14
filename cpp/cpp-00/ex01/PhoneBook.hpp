#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

using namespace std;

class PhoneBook
{

	public:

		PhoneBook();
		// PhoneBook( PhoneBook const & src );
		~PhoneBook();

		// PhoneBook &		operator=( PhoneBook const & rhs );

		void add(Contact new_contact);
		int  get_contact_index();
		Contact* get();
	private:
		int contact_index;
		Contact contacts[8];

};

// std::ostream &			operator<<( std::ostream & o, PhoneBook const & i );

#endif /* ******************************************************* PHONEBOOK_H */