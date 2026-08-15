#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other) {
    *this = other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other; // Kopyalanacak değişken yok
    return *this;
}
AForm *Intern::makeShrubberyCreationForm(std::string target) const {
    return new ShrubberyCreationForm(target);
}
AForm *Intern::makeRobotomyRequestForm(std::string target) const {
    return new RobotomyRequestForm(target);
}
AForm *Intern::makePresidentialPardonForm(std::string target) const {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target) const {
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm *(Intern::*f[])(std::string) const = {
        &Intern::makeShrubberyCreationForm,
        &Intern::makeRobotomyRequestForm,
        &Intern::makePresidentialPardonForm
    };
    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*f[i])(target);
        }
    }
    throw FormNotFoundException();    
}

const char *Intern::FormNotFoundException::what() const throw() {
    return "Form not found!";
}
