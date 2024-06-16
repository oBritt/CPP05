#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat god("god", 1);
	Bureaucrat weak("weak", 150);

	ShrubberyCreationForm  Shrubbery("bro");
	PresidentialPardonForm Presidential("dude");
	RobotomyRequestForm    Robotomy("man");
	
	std::cout << "----------------------------------------" << std::endl;
		weak.signForm(Shrubbery);
		weak.signForm(Presidential);
		weak.signForm(Robotomy);

		std::cout << "-----" << std::endl;

		god.executeForm(Shrubbery);
		god.executeForm(Presidential);
		god.executeForm(Robotomy);

		std::cout << "-----" << std::endl;
		god.signForm(Shrubbery);
		god.signForm(Presidential);
		god.signForm(Robotomy);
		std::cout << "-----" << std::endl;
		
		god.executeForm(Shrubbery);
		std::cout << "+" << std::endl;
		god.executeForm(Presidential);
		std::cout << "+" << std::endl;
		god.executeForm(Robotomy);
        god.executeForm(Robotomy);
        god.executeForm(Robotomy);
        god.executeForm(Robotomy);
		std::cout << "+" << std::endl;
	
		std::cout << "-----" << std::endl;
		weak.executeForm(Shrubbery);
		weak.executeForm(Presidential);
		weak.executeForm(Robotomy);
		// std::cout << "-----" << std::endl;

	std::cout << "----------------------------------------" << std::endl;
	return 0;
}