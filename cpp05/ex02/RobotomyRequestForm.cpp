#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
    if (this != &copy)
    {
        AForm::operator=(copy);
        this->_target = copy._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw AForm::NotSignedException(); // İmzasızsa NotSignedException fırlat
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException(); // Rütbe yetmiyorsa hata fırlat

    // Rastgele ses çıkar
    std::cout << "* BRRR... VRRR... DRRR... *";
    
    // %50 ihtimalle başarılı
    if (std::rand() % 2 == 0)
        std::cout << " Robotomyzed " << _target << " successfully!" << std::endl;
    else
        std::cout << " Robotomy failed for " << _target << "." << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
    return this->_target;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& robotomyRequestForm)
{
    os << robotomyRequestForm.getName() << ", Status: " << robotomyRequestForm.getIsSigned() << ", Sign Grade: " << robotomyRequestForm.getGradeToSign() << ", Exec Grade: " << robotomyRequestForm.getGradeToExecute() << ", Target: " << robotomyRequestForm.getTarget();
    return os;
}
