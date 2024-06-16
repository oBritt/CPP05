

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm::AForm("ShrubberyCreationForm", 25, 5)
{
    std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm default deconstructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm::AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm target constructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & other)
{
    std::cout << "ShrubberyCreationForm assignment operator " << std::endl;
    if (this != &other)
    {
        this->target = other.target;
        this->setStatus(other.getStatus());
    }
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other): AForm::AForm("ShrubberyCreationForm", 145, 137), target(other.target)
{
    this->setStatus(other.getStatus());
    std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->getStatus())
    {
        throw AForm::NotSignedException();
    }
    else if (executor.getGrade() > this->getExec())
    {
        throw AForm::GradeTooLowException();
    }
    else
    {
        std::string temp;
        temp = target + "_shrubbery";
        std::ofstream o(temp.c_str(), std::ios::trunc);
        if (o.is_open() == 0)
            std::cerr << "Target file `" << temp.c_str() << " can't be opened" << std::endl;
        else
        {
            o << "          v .   ._, |_  ., \n           `-._\\/  .  \\ /    |/_ \n               \\\\  _\\, y | \\// \n         _\\_.___\\, \\/ -.\\|| \n           `7-,--.`._||  / / , \n           /'     `-. `./ / |/_.' \n                     |    |// \n                     |_    / \n                     |-   | \n                     |   =| \n                     |    | \n--------------------/ ,  . \\--------._" << std::endl;
            o.close();
        }
    }
}