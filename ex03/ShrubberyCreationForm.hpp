

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(ShrubberyCreationForm const & other);

    public:
        ~ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const & other);
        virtual	void 	execute(Bureaucrat const & executor) const;

};