#pragma once

#include <iostream>

class AForm;

class Intern {
    private : 
    AForm *makeShrubberyCreationForm(std::string target) const;
    AForm *makeRobotomyRequestForm(std::string target) const;
    AForm *makePresidentialPardonForm(std::string target) const;
    
    public:
    Intern();
    ~Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);

    AForm *makeForm(std::string formName, std::string target) const;
    
    class FormNotFoundException : public std::exception 
    {
        public:
            virtual const char *what() const throw();
    };

};

