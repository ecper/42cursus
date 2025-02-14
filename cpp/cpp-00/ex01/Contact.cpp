#include "Contact.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Contact::Contact()
{
}

// Contact::Contact( const Contact & src )
// {
// }


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Contact::~Contact()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// Contact &				Contact::operator=( Contact const & rhs )
// {
// 	//if ( this != &rhs )
// 	//{
// 		//this->_value = rhs.getValue();
// 	//}
// 	return *this;
// }

// std::ostream &			operator<<( std::ostream & o, Contact const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

void Contact::set_first_name(string first_name)
{
	m_first_name = first_name; 
}

void Contact::set_last_name(string last_name)
{
	m_last_name = last_name; 
}


void Contact::set_nick_name(string nick_name)
{
	m_nick_name = nick_name; 
}


void Contact::set_phone_number(string phone_number)
{
	m_phone_number = phone_number; 
}


void Contact::set_darkest_secret(string darkest_secret)
{
	m_darkest_secret = darkest_secret; 
}

void Contact::set_index(int index)
{
	m_index = index;
}


string Contact::get_first_name()
{
	return (m_first_name); 
}

string Contact::get_last_name()
{
	return (m_last_name); 
}


string Contact::get_nick_name()
{
	return (m_nick_name); 
}


string Contact::get_phone_number()
{
	return (m_phone_number); 
}


string Contact::get_darkest_secret()
{
	return (m_darkest_secret); 
}

int Contact::get_index()
{
	return (m_index);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */