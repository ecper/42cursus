#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	this->setName("default");
	this->setIsGradeSigned(false);
	this->setGradeSigned(145);
	this->setGradeExecuted(137);
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : AForm(src)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	this->setName("default");
	this->setIsGradeSigned(false);
	this->setGradeSigned(145);
	this->setGradeExecuted(137);
	this->doSomething(target);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::doSomething( std::string target )
{
	std::ofstream MyFile(target + "_shrubbery");
	MyFile << "test";
	MyFile.close();
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */