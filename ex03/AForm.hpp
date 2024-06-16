

#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <fstream>

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool        is_signed;
        const int         sign_grade_required;
        const int         exec_grade_required;
    
    public:
        AForm(void);
        virtual ~AForm(void);
        AForm(std::string name, int sign_grade_required, int exec_grade_requiered);
        AForm& operator=(AForm const &other);
        AForm(AForm const &other);

        std::string getName(void) const;
        bool        getStatus(void) const;
        int         getSign(void) const;
        int         getExec(void) const;
        void        setStatus(bool set);

        virtual void   execute(Bureaucrat const & executor) const = 0;
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

        class NotSignedException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };

};

std::ostream& operator<<(std::ostream & o, AForm const &f);

#endif