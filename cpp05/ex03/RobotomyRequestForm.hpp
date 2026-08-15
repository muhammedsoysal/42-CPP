#pragma once

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
    std::string _target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
    ~RobotomyRequestForm();
    void    execute(Bureaucrat const & executor) const;
    std::string getTarget() const;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& robotomyRequestForm);
