#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Default Constructor
AForm::AForm() : _name("Default AForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

// Parameter Constructor
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
}

// Copy Constructor
AForm::AForm(const AForm& other) 
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{}

// Copy Assignment Operator
AForm& AForm::operator=(const AForm& copy)
{
    if (this != &copy)
    {
        _isSigned = copy._isSigned;
        // _name, _gradeToSign, ve _gradeToExecute const olduğu için burada değiştirilemezler!
    }
    return *this;
}

// Destructor
AForm::~AForm() {}

// Getters
std::string AForm::getName(void) const { return _name; }
int AForm::getGradeToSign(void) const { return _gradeToSign; }
int AForm::getGradeToExecute(void) const { return _gradeToExecute; }
bool AForm::getIsSigned(void) const { return _isSigned; }

// beSigned Metodu
void AForm::beSigned(Bureaucrat& b)
{
    if (b.getGrade() > _gradeToSign) // Sayı olarak büyükse rütbesi düşüktür!
        throw GradeTooLowException();
    _isSigned = true;
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm Grade is too low!";
}

const char* AForm::NotSignedException::what() const throw()
{
    return "AForm is not signed!";
}

// Operator Overload
std::ostream& operator<<(std::ostream& os, const AForm& aform)
{
    os << "AForm: " << aform.getName() 
       << ", Status: " << (aform.getIsSigned() ? "Signed" : "Not Signed")
       << ", Grade required to sign: " << aform.getGradeToSign()
       << ", Grade required to execute: " << aform.getGradeToExecute();
    return os;
}
