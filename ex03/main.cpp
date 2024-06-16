#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;
	}
	{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	delete rrf;
	}
	{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("shubbery creation", "Bender");
	delete rrf;
	}
	{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("shu request", "Bender");
	delete rrf;
	}
}