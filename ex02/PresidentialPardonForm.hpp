

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
        PresidentialPardonForm(void);
        PresidentialPardonForm(PresidentialPardonForm const & other);

    public:
        ~PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm& operator=(PresidentialPardonForm const & other);
        void execute(Bureaucrat const & executor) const;

};