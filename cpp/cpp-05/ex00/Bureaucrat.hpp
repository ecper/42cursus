#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat( const int _grade );
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		std::string getName( void );
		int getGrade( void );

		void incrementGrade( void );
		void decrementGrade( void );
		void setGrade( const int _grade);

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	private:
		std::string name;
		int grade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat  &i );

#endif /* ****************************************************** BUREAUCRAT_H */