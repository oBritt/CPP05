

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
        RobotomyRequestForm(void);
        RobotomyRequestForm(RobotomyRequestForm const & other);

    public:
        ~RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm& operator=(RobotomyRequestForm const & other);
        void execute(Bureaucrat const & executor)  const;

};