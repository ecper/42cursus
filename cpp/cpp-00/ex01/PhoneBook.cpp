#include "PhoneBook.hpp"
#include <iostream>

using namespace std;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PhoneBook::PhoneBook()
{
	contact_index = 0;
}

// PhoneBook::PhoneBook( const PhoneBook & src )
// {
// }


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PhoneBook::~PhoneBook()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// PhoneBook &				PhoneBook::operator=( PhoneBook const & rhs )
// {
// 	//if ( this != &rhs )
// 	//{
// 		//this->_value = rhs.getValue();
// 	//}
// 	return *this;
// }

// std::ostream &			operator<<( std::ostream & o, PhoneBook const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

void PhoneBook::add(Contact new_contact)
{
	if (contact_index >= 8)
	{
		for (int i = 7; i > 1; i--)
			contacts[i] = contacts[i - 1];
		contacts[0] = new_contact;
		return ;
	}
	new_contact.set_index(contact_index);
	contacts[contact_index] = new_contact;
	cout << "first name: " + contacts[0].get_first_name() + " added" << endl;
	contact_index++;
}

Contact* PhoneBook::get()
{
	return contacts;
}

int PhoneBook::get_contact_index()
{
	return contact_index;
}

// Contact PhoneBook::search_contact(int index)
// {

// }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */