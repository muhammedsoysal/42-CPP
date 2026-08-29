#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
    Bureaucrat boss("Boss", 1);
    Intern someRandomIntern;
    
    std::cout << "\nIntern success test:" << std::endl;
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }
    
    std::cout << "\nIntern fail test:" << std::endl;
    try {
        someRandomIntern.makeForm("unknown form", "Nobody");
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    return 0;
}
