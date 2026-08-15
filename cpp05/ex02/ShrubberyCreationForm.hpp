#pragma once

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
    std::string _target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
    ~ShrubberyCreationForm();
    void    execute(Bureaucrat const & executor) const;
    std::string getTarget() const;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& shrubberyCreationForm);
