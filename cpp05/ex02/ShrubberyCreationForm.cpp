#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
    this->_target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137)
{
    this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
    this->_target = other._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
    if (this != &copy)
    {
        AForm::operator=(copy);
        this->_target = copy._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::ofstream file((this->_target + "_shrubbery").c_str());
    if (!file.is_open())
        return;
    file << "      /\\      \n";
    file << "     /  \\     \n";
    file << "    /    \\    \n";
    file << "   /      \\   \n";
    file << "  /        \\  \n";
    file << " /          \\ \n";
    file << "/____________\\\n";
    file << "     ||       \n";
    file.close();
}

std::string ShrubberyCreationForm::getTarget() const
{
    return this->_target;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& shrubberyCreationForm)
{
    os << shrubberyCreationForm.getName() << ", Status: " << shrubberyCreationForm.getIsSigned() << ", Sign Grade: " << shrubberyCreationForm.getGradeToSign() << ", Exec Grade: " << shrubberyCreationForm.getGradeToExecute() << ", Target: " << shrubberyCreationForm.getTarget();
    return os;
}
