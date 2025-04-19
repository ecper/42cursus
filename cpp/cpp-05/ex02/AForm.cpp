#include "AForm.hpp"
#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm() : name("default"), isGradeSigned(false), gradeSigned(150), gradeExecuted(150)
{
	std::cout << "AForm default Constructor called" << std::endl;
}

AForm::AForm( const AForm & src ) : name(src.name), isGradeSigned(src.isGradeSigned), gradeSigned(src.gradeSigned), gradeExecuted(src.gradeExecuted)
{
	std::cout << "AForm copy Constructor called" << std::endl;
}

AForm::AForm(std::string _name, int _gradeSigned, int _gradeExecuted ) : name(_name), isGradeSigned(false), gradeSigned(_gradeSigned), gradeExecuted(_gradeExecuted)
{
	std::cout << "AForm constructor called" << std::endl;
	if (this->gradeSigned > 150 || this->gradeExecuted > 150)
		throw AForm::GradeTooLowException();
	else if (this->gradeSigned < 1 || this->gradeExecuted < 1)
		throw AForm::GradeTooHighException();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
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

std::ostream &			operator<<( std::ostream & o, AForm  &i )
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

void AForm::beSigned(  Bureaucrat & Bureaucrat )
{
	if (Bureaucrat.getGrade() > this->gradeSigned)
		throw AForm::GradeTooLowException();
	else if (this->isGradeSigned != true)
		this->isGradeSigned = true;
	else
		std::cout << "already signed" << std::endl;
}

const char *AForm::GradeTooLowException::what( void ) const throw()
{
	return ("Grade too low");
};

const char *AForm::GradeTooHighException::what( void ) const throw()
{
	return ("Grade too high");
};


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string AForm::getName( void )
{
	return (this->name);
}

bool AForm::getIsGradeSigned( void )
{
	return (this->isGradeSigned);
}

int AForm::getGradeSigned( void )
{
	return (this->gradeSigned);
}

int AForm::getGradeExecuted( void )
{
	return (this->gradeExecuted);
}

void AForm::setName( std::string _name )
{
	this->name = _name;
}

void AForm::setIsGradeSigned( bool _isGradeSigned )
{
	this->isGradeSigned = _isGradeSigned;
}

void AForm::setGradeSigned( int _gradeSigned )
{
	this->gradeSigned = _gradeSigned;
}

void AForm::setGradeExecuted( int _gradeExecuted )
{
	this->gradeExecuted = _gradeExecuted;
}


/* ************************************************************************** */