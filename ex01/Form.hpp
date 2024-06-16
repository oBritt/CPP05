

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool        is_signed;
        const int         sign_grade_required;
        const int         exec_grade_required;
    
    public:
        Form(void);
        ~Form(void);
        Form(std::string name, int sign_grade_required, int exec_grade_requiered);
        Form& operator=(Form const &other);
        Form(Form const &other);

        std::string getName(void) const;
        bool        getStatus(void) const;
        int         getSign(void) const;
        int         getExec(void) const;

        void    beSigned(Bureaucrat const & b);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };

        class AlreadySignedException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };

};

std::ostream& operator<<(std::ostream & o, Form const &f);

#endif