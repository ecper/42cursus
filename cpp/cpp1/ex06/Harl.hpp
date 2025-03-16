#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{

	public:

		Harl();
		~Harl();
		void complain( std::string level );
		void filterComplain( std::string level );

	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};


#endif /* ************************************************************ HARL_H */