#include "Form.hpp"
#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : name("default"), isGradeSigned(false), gradeSigned(150), gradeExecuted(150)
{
	std::cout << "Form default Constructor called" << std::endl;
}

Form::Form( const Form & src ) : name(src.name), isGradeSigned(src.isGradeSigned), gradeSigned(src.gradeSigned), gradeExecuted(src.gradeExecuted)
{
	std::cout << "Form copy Constructor called" << std::endl;
}

Form::Form(std::string _name, int _gradeSigned, int _gradeExecuted ) : name(_name), isGradeSigned(false), gradeSigned(_gradeSigned), gradeExecuted(_gradeExecuted)
{
	std::cout << "Form constructor called" << std::endl;
	if (this->gradeSigned > 150 || this->gradeExecuted > 150)
		throw Form::GradeTooLowException();
	else if (this->gradeSigned < 1 || this->gradeExecuted < 1)
		throw Form::GradeTooHighException();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->isGradeSigned = rhs.isGradeSigned;
		this->gradeSigned = rhs.gradeSigned;
		this->gradeExecuted = rhs.gradeExecuted;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form  &i )
{
	o << "name: " << i.getName() 
	<< ", isSigned: " << i.getIsGradeSigned()
	<< ", gradeSigned: " << i.getGradeSigned()
	<< ", gradeExecuted: " << i.getGradeExecuted()
	<< std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(  Bureaucrat & Bureaucrat )
{
	if (Bureaucrat.getGrade() > this->gradeSigned)
		throw Form::GradeTooLowException();
	else if (this->isGradeSigned != true)
		this->isGradeSigned = true;
	else
		std::cout << "already signed" << std::endl;
}

const char *Form::GradeTooLowException::what( void ) const throw()
{
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what( void ) const throw()
{
	return ("Grade too high");
};


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Form::getName( void )
{
	return (this->name);
}

bool Form::getIsGradeSigned( void )
{
	return (this->isGradeSigned);
}

int Form::getGradeSigned( void )
{
	return (this->gradeSigned);
}

int Form::getGradeExecuted( void )
{
	return (this->gradeExecuted);
}


/* ************************************************************************** */