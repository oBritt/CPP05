

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm::AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm default deconstructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm::AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm target constructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & other)
{
    std::cout << "PresidentialPardonForm assignment operator " << std::endl;
    if (this != &other)
    {
        this->target = other.target;
        this->setStatus(other.getStatus());
    }
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other): AForm::AForm("PresidentialPardonForm", 25, 5), target(other.target)
{
    this->setStatus(other.getStatus());
    std::cout << "PresidentialPardonForm copy constructor" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
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
        std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
}