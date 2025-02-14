#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

using namespace std;

class Contact
{

	public:

		Contact();
		// Contact( Contact const & src );
		~Contact();

		// Contact &		operator=( Contact const & rhs );


		void set_first_name(string first_name);
		void set_last_name(string last_name);
		void set_nick_name(string nick_name);
		void set_phone_number(string phone_number);
		void set_darkest_secret(string darkest_secret);
		void set_index(int index);

		string get_first_name();
		string get_last_name();
		string get_nick_name();
		string get_phone_number();
		string get_darkest_secret();
		int get_index();
	private:
		int	m_index;
		string m_first_name;
		string m_last_name;
		string m_nick_name;
		string m_phone_number;
		string m_darkest_secret;
};

// std::ostream &			operator<<( std::ostream & o, Contact const & i );

#endif /* ********************************************************* CONTACT_H */