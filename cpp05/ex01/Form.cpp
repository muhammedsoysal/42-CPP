#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default Constructor
Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

// Parameter Constructor
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
}

// Copy Constructor
Form::Form(const Form& other) 
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{}

// Copy Assignment Operator
Form& Form::operator=(const Form& copy)
{
    if (this != &copy)
    {
        _isSigned = copy._isSigned;
    }
    return *this;
}

// Destructor
Form::~Form() {}

// Getters
std::string Form::getName(void) const { return _name; }
int Form::getGradeToSign(void) const { return _gradeToSign; }
int Form::getGradeToExecute(void) const { return _gradeToExecute; }
bool Form::getIsSigned(void) const { return _isSigned; }

// beSigned Metodu
void Form::beSigned(Bureaucrat& b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw()
{
    return "Form Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form Grade is too low!";
}

// Operator Overload
std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form: " << form.getName() 
       << ", Status: " << (form.getIsSigned() ? "Signed" : "Not Signed")
       << ", Grade required to sign: " << form.getGradeToSign()
       << ", Grade required to execute: " << form.getGradeToExecute();
    return os;
}
