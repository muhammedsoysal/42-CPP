#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);

        Form importantForm("Top Secret Form", 50, 20);
        Form easyForm("Coffee Request", 150, 150);

        std::cout << "--- Initial Form Statuses ---" << std::endl;
        std::cout << importantForm << std::endl;
        std::cout << easyForm << std::endl;

        std::cout << "\n--- Intern tries to sign forms ---" << std::endl;
        intern.signForm(easyForm); // Should succeed
        intern.signForm(importantForm); // Should fail

        std::cout << "\n--- Boss tries to sign forms ---" << std::endl;
        boss.signForm(importantForm); // Should succeed

        std::cout << "\n--- Final Form Statuses ---" << std::endl;
        std::cout << importantForm << std::endl;
        std::cout << easyForm << std::endl;

        std::cout << "\n--- Trying to create invalid form ---" << std::endl;
        Form impossibleForm("Impossible", 0, 150); // Will throw exception
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}