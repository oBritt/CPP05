
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat c =  Bureaucrat("bob", -1);
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    try
    {
        Bureaucrat c =  Bureaucrat("bob",222);
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat c =  Bureaucrat("bob", 150);
        std::cout << c << std::endl;
        c.decrementGrade();
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
