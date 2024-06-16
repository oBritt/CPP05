

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm::AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm default deconstructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm::AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm target constructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & other)
{
    std::cout << "RobotomyRequestForm assignment operator " << std::endl;
    if (this != &other)
    {
        this->target = other.target;
        this->setStatus(other.getStatus());
    }
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other): AForm::AForm("RobotomyRequestForm", 72, 45), target(other.target)
{
    this->setStatus(other.getStatus());
    std::cout << "RobotomyRequestForm copy constructor" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
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
        int i = rand() % 2;
        if (i)
            std::cout << "robotomy failed" << std::endl;
        else
            std::cout << this->target << " has been robotomized " << std::endl;
    }
}