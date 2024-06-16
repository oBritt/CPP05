
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat{

    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat(void);
        ~Bureaucrat(void);
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(Bureaucrat const &other);
        Bureaucrat& operator=(Bureaucrat const &other);
        void    incrementGrade(void);
        void    decrementGrade(void);
        std::string getName(void) const;
        int getGrade(void) const;
        void setGrade(int grade);
        void signForm(AForm &f);

        void executeForm(AForm const & form);

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream & o, Bureaucrat const &b);

#endif