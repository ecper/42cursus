#include "Bureaucrat.hpp"

int main ( void )
{
    try {
        Bureaucrat a;
        Bureaucrat b(19);

        for (int i = 150; i > 1; i--)
        {
            a.decrementGrade();
            std::cout << a << std::endl;
        }
        for (int i = 150; i > 0; i--)
        {
            b.decrementGrade();
            std::cout << b << std::endl;
        }
        return (0);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return (1);
    }
}