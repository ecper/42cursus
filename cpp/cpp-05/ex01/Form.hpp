#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

class Bureaucrat;

class Form
{

	public:

		Form();
		Form( Form const & src );
		Form( std::string _name, int _gradeSigned, int _gradeExecuted );
		~Form();

		Form &		operator=( Form const & rhs );

		std::string getName( void );
		bool getIsGradeSigned( void );
		int getGradeSigned( void );
		int getGradeExecuted( void );

		void beSigned( Bureaucrat & bureaucrat );

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
		bool isGradeSigned;
		int gradeSigned;
		int gradeExecuted;


};

std::ostream &			operator<<( std::ostream & o, Form &i );

#endif /* ************************************************************ FORM_H */