

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
    public:
        Intern(void);
        ~Intern(void);
        Intern& operator=(Intern const &other);
        Intern(Intern const &other);
        AForm* makeForm(std::string form, std::string target);
};