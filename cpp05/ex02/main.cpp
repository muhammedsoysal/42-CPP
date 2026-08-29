#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    std::srand(std::time(0));

    std::cout << "\nCreating bureaucrats and forms:" << std::endl;
    
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

    std::cout << "\nShrubbery form test:" << std::endl;
    
    teaBoy.signForm(treeForm);        // Fails (150 > 145)
    intern.executeForm(treeForm);     // Fails (Not signed)
    intern.signForm(treeForm);        // Succeeds (140 <= 145)
    intern.executeForm(treeForm);     // Fails (140 > 137)
    manager.executeForm(treeForm);    // Succeeds (40 <= 137) - Creates file!

    std::cout << "\nRobotomy form test:" << std::endl;
    
    intern.signForm(robotForm);       // Fails
    manager.signForm(robotForm);      // Succeeds (40 <= 72)
    manager.executeForm(robotForm);   // Succeeds (40 <= 45) -> 50% chance
    manager.executeForm(robotForm);   // Multiple times to see the 50% chance
    manager.executeForm(robotForm);
    manager.executeForm(robotForm);

    std::cout << "\nPresidential pardon form test:" << std::endl;
    
    manager.signForm(pardonForm);     // Fails (40 > 25)
    boss.signForm(pardonForm);        // Succeeds
    manager.executeForm(pardonForm);  // Fails (40 > 5)
    boss.executeForm(pardonForm);     // Succeeds (1 <= 5)

    std::cout << "\nHeap allocation test:" << std::endl;

    AForm* heapForm = new PresidentialPardonForm("Trillian");
    boss.signForm(*heapForm);
    boss.executeForm(*heapForm);
    delete heapForm;

    std::cout << "\nEnd of tests." << std::endl;

    return 0;
}
