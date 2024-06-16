

#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Intern was born" << std::endl;
}

Intern::~Intern(void)
{
    std::cout << "Intern died" << std::endl;
}

Intern& Intern::operator=(Intern const & other)
{
    std::cout << "INtern assignment" << std::endl;
    (void)other;
    return (*this);
}

Intern::Intern(Intern const & other)
{
    std::cout << "Intern copy constructor" << std::endl;
    (void)other;
}

AForm* Intern::makeForm(std::string form, std::string target)
{

    std::string a[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

    int i = 0;
    for (; i < 4; i++)
    {
        if (i == 3 || a[i] == form)
            break ;
        
    }
    AForm *ptr;
    switch (i)
    {
    case 0:
        ptr =  new RobotomyRequestForm(target);
        std::cout << "Intern creates " << form << std::endl;
        return (ptr);
    case 1:
        ptr =  new RobotomyRequestForm(target);
        std::cout << "Intern creates " << form << std::endl;
        return (ptr);
    case 2:
        ptr = new RobotomyRequestForm(target);
        std::cout << "Intern creates " << form << std::endl;
        return (ptr);
    
    default:
        std::cout << "Form doesnt exists" << std::endl;;
        return (NULL);
    }
}