#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const int _grade ) : name("default")
{
	std::cout << "Bureaucrat _grade init constructor called" << std::endl;
	this->setGrade(_grade);
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : name(src.name)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	this->setGrade(src.grade);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	std::cout << "Bureaucrat equals operator called" << std::endl;
	if ( this != &rhs )
	{
		this->name = rhs.name;
		this->setGrade(rhs.grade);
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat  &i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << "." << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void  Bureaucrat::incrementGrade( void )
{
	std::cout << "increment grade" << std::endl;
	this->setGrade(this->grade + 1);
}

void  Bureaucrat::decrementGrade( void )
{
	std::cout << "decrement grade" << std::endl;
	this->setGrade(this->grade - 1);
}

void Bureaucrat::setGrade( const int _grade )
{
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = _grade;
}

const char *Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("Grade too high");
};

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Bureaucrat::getName( void )
{
	return (this->name);
}

int Bureaucrat::getGrade( void )
{
	return (this->grade);
}




/* ************************************************************************** */