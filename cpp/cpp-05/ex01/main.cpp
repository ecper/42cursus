#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ( void )
{
    {
        Bureaucrat a;
        Form b;

        try {
            b.beSigned(a);
            std::cout << a.getName() << " signed " << b.getName() << std::endl;
        } catch (Form::GradeTooLowException &e)
        {
            std::cerr << a.getName() << " was not able to sign " << b.getName() << ": " << e.what() << std::endl;
        }
    }

    {
        Bureaucrat a(145);
        Form b("b1", 143, 143);

        try {
            b.beSigned(a);
            std::cout << a.getName() << " signed " << b.getName() << std::endl;
        } catch (Form::GradeTooLowException &e)
        {
            std::cerr << a.getName() << " was not able to sign " << b.getName() << ": " << e.what() << std::endl;
        }
    }

    {
        Bureaucrat a(145);
        Form b("b1", 143, 143);
        a.signForm(b);
    }

}