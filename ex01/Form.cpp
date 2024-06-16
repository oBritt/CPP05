

#include "Form.hpp"

Form::Form(void):name("Default"), is_signed(0), sign_grade_required(150), exec_grade_required(150)
{
    std::cout << "Form default constructor" << std::endl;
}

Form::~Form(void)
{
    std::cout << "Form default deconstructor" << std::endl;
}

Form::Form(std::string name, int sign_grade_required, int exec_grade_required): name(name), \
is_signed(0), sign_grade_required(sign_grade_required), exec_grade_required(exec_grade_required)
{
    if (sign_grade_required > 150)
        throw Form::GradeTooLowException();
    else if (sign_grade_required < 1)
        throw Form::GradeTooHighException();
    
    if (exec_grade_required > 150)
        throw Form::GradeTooLowException();
    else if (exec_grade_required < 1)
        throw Form::GradeTooHighException();
    
    std::cout << "Form " << name << " was constructed" << std::endl;
}

Form::Form(Form const & other): name(other.name), is_signed(other.is_signed), sign_grade_required(other.sign_grade_required), \
exec_grade_required(other.exec_grade_required)
{
    std::cout << "Form copy constructor" << std::endl;
}

Form &Form::operator=(Form const &other)
{
    if (this != &other)
    {
        this->~Form();
        *this = Form(other);
    }
    return *this;
}

std::string Form::getName(void) const
{
    return this->name;
}

bool Form::getStatus(void) const
{
    return this->is_signed;
}

int Form::getExec(void) const
{
    return this->exec_grade_required;
}

int Form::getSign(void) const
{
    return this->sign_grade_required;
}

void    Form::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() > this->sign_grade_required)
        throw Form::GradeTooLowException();
    else if (this->is_signed)
        throw Form::AlreadySignedException();
    else
        this->is_signed = 1;
}

std::ostream& operator<<(std::ostream &o, Form const & f)
{
    o << "Name: " << f.getName() << " Status: " << f.getStatus() << " Sign_requiment: " << f.getSign();
    o << " Exec_requiment: " << f.getExec();
    return (o);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade too low";
}

const char *Form::AlreadySignedException::what() const throw()
{
    return "Form already signed";
}

