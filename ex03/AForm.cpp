

#include "AForm.hpp"

AForm::AForm(void):name("Default"), is_signed(0), sign_grade_required(150), exec_grade_required(150)
{
    std::cout << "AForm default constructor" << std::endl;
}

AForm::~AForm(void)
{
    std::cout << "AForm default deconstructor" << std::endl;
}

AForm::AForm(std::string name, int sign_grade_required, int exec_grade_required): name(name), \
is_signed(0), sign_grade_required(sign_grade_required), exec_grade_required(exec_grade_required)
{
    if (sign_grade_required > 150)
        throw AForm::GradeTooLowException();
    else if (sign_grade_required < 1)
        throw AForm::GradeTooHighException();
    
    if (exec_grade_required > 150)
        throw AForm::GradeTooLowException();
    else if (exec_grade_required < 1)
        throw AForm::GradeTooHighException();
    
    std::cout << "AForm " << name << " was constructed" << std::endl;
}

AForm::AForm(AForm const & other): name(other.name), is_signed(other.is_signed), sign_grade_required(other.sign_grade_required), \
exec_grade_required(other.exec_grade_required)
{
    std::cout << "AForm copy constructor" << std::endl;
}

std::string AForm::getName(void) const
{
    return this->name;
}

bool AForm::getStatus(void) const
{
    return this->is_signed;
}

int AForm::getExec(void) const
{
    return this->exec_grade_required;
}

int AForm::getSign(void) const
{
    return this->sign_grade_required;
}

void AForm::setStatus(bool set)
{
    this->is_signed = set;
}

void    AForm::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() > this->sign_grade_required)
        throw AForm::GradeTooLowException();
    else if (this->is_signed)
        throw AForm::AlreadySignedException();
    else
        this->is_signed = 1;
}

std::ostream& operator<<(std::ostream &o, AForm const & f)
{
    o << "Name: " << f.getName() << " Status: " << f.getStatus() << " Sign_requiment: " << f.getSign();
    o << " Exec_requiment: " << f.getExec();
    return (o);
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade too low";
}

const char *AForm::AlreadySignedException::what() const throw()
{
    return "AForm already signed";
}

const char *AForm::NotSignedException::what() const throw()
{
    return "AForm is not signed yet";
}