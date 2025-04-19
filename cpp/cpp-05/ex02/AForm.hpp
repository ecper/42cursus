#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>

class Bureaucrat;

class AForm
{

	public:

		AForm();
		AForm( AForm const & src );
		AForm( std::string _name, int _gradeSigned, int _gradeExecuted );
		virtual ~AForm();

		AForm &		operator=( AForm const & rhs );

		std::string getName( void );
		bool getIsGradeSigned( void );
		int getGradeSigned( void );
		int getGradeExecuted( void );

		void setName( std::string _name );
		void setIsGradeSigned( bool _isGradeSigned );
		void setGradeSigned( int _gradeSigned );
		void setGradeExecuted( int _gradeExecuted );

		void beSigned( Bureaucrat & bureaucrat );

		virtual void doSomething( std::string target ) = 0;

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

std::ostream &			operator<<( std::ostream & o, AForm &i );

#endif /* ************************************************************ AFORM_H */