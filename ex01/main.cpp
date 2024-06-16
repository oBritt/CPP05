
#include "Bureaucrat.hpp"

int main()
{
    {
        Bureaucrat b("bob", 10);
        Form       f("form", 22, 31);
        std::cout << f << std::endl;
        b.signForm(f);
        b.signForm(f);
    }
    std::cout << std::endl;
    std::cout << std::endl;
    {
        try
        {
            Form f("form", -1, 22);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    std::cout << std::endl;
    std::cout << std::endl;
    {

        Bureaucrat b("bob", 100);
        Form       f("nice", 1, 1);
        b.signForm(f);
        
    }
}
