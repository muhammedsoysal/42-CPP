#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "[1] CREATING BUREAUCRATS AND FORMS" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    
    Bureaucrat boss("Boss", 1);
    Bureaucrat manager("Manager", 40);
    Bureaucrat intern("Intern", 140);
    Bureaucrat teaBoy("Tea Boy", 150);

    ShrubberyCreationForm treeForm("Garden");
    RobotomyRequestForm robotForm("Bender");
    PresidentialPardonForm pardonForm("Arthur Dent");

    std::cout << boss << "\n" << manager << "\n" << intern << "\n" << teaBoy << std::endl;
    std::cout << std::endl;
    std::cout << treeForm << "\n" << robotForm << "\n" << pardonForm << std::endl;

    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "[2] SHRUBBERY FORM TEST (Sign: 145, Exec: 137)" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    
    teaBoy.signForm(treeForm);        // Fails (150 > 145)
    intern.executeForm(treeForm);     // Fails (Not signed)
    intern.signForm(treeForm);        // Succeeds (140 <= 145)
    intern.executeForm(treeForm);     // Fails (140 > 137)
    manager.executeForm(treeForm);    // Succeeds (40 <= 137) - Creates file!

    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "[3] ROBOTOMY FORM TEST (Sign: 72, Exec: 45)" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    
    intern.signForm(robotForm);       // Fails
    manager.signForm(robotForm);      // Succeeds (40 <= 72)
    manager.executeForm(robotForm);   // Succeeds (40 <= 45) -> 50% chance
    manager.executeForm(robotForm);   // Multiple times to see the 50% chance
    manager.executeForm(robotForm);
    manager.executeForm(robotForm);

    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "[4] PRESIDENTIAL PARDON FORM TEST (Sign: 25, Exec: 5)" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    
    manager.signForm(pardonForm);     // Fails (40 > 25)
    boss.signForm(pardonForm);        // Succeeds
    manager.executeForm(pardonForm);  // Fails (40 > 5)
    boss.executeForm(pardonForm);     // Succeeds (1 <= 5)

    std::cout << "\n-------------------------------------------------------" << std::endl;
    std::cout << "END OF TESTS" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;

    return 0;
}
