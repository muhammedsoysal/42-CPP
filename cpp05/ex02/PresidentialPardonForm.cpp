#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
    if (this != &copy)
    {
        AForm::operator=(copy);
        this->_target = copy._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
    return this->_target;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& presidentialPardonForm)
{
    os << presidentialPardonForm.getName() << ", Status: " << presidentialPardonForm.getIsSigned()
        << ", Sign Grade: " << presidentialPardonForm.getGradeToSign()
        << ", Exec Grade: " << presidentialPardonForm.getGradeToExecute()
        << ", Target: " << presidentialPardonForm.getTarget();
    return os;
}
