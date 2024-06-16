
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): name("Default"), grade(150)
{
    std::cout << "Default Bureaucrat was created" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat " << this->name << " was deconstructed" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(150)
{
    setGrade(grade);
    std::cout << "Bureaucrat " << this->name << " was constructed" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & other): name(other.name), grade(other.grade)
{
    std::cout << "Copy constructor was called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const & other)
{
    std::cout << "Assignment operator was called" << std::endl;
    if (this != &other)
    {
        this->~Bureaucrat();
        *this = Bureaucrat(other);
    }
    return (*this);
}

std::string Bureaucrat::getName(void) const
{
    return this->name;
}

int Bureaucrat::getGrade(void) const
{
    return this->grade;
}

void    Bureaucrat::incrementGrade(void)
{
    setGrade(this->grade - 1);
}

void    Bureaucrat::decrementGrade(void)
{
    setGrade(this->grade + 1);
}

void    Bureaucrat::setGrade(int grade)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade = grade;
}

std::ostream& operator<<(std::ostream &o, Bureaucrat const & b)
{ 
    o << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (o);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade to high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade to low";
}