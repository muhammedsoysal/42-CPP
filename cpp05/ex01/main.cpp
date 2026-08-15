#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);

        Form f1("Important Form", 50, 50);
        Form f2("Normal Form", 150, 150);

        std::cout << f1 << "\n" << f2 << std::endl;

        intern.signForm(f1); // Fails
        intern.signForm(f2); // Succeeds
        boss.signForm(f1);   // Succeeds

        std::cout << "\n" << f1 << "\n" << f2 << std::endl;

        Form invalidForm("Invalid", 0, 150); // Throws exception
    }
    catch (std::exception &e) {
        std::cout << "\nException: " << e.what() << std::endl;
    }

    return 0;
}