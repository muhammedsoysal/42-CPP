#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    AForm();    
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& copy);
    virtual ~AForm();

    void    beSigned(Bureaucrat& b);

    std::string         getName(void) const;
    int                 getGradeToSign(void) const;
    int                 getGradeToExecute(void) const;
    bool                getIsSigned(void) const;
    virtual void        execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char* what() const throw();
    };
    class NotSignedException : public std::exception
    {
        public:
            const char* what() const throw();
    };

};

std::ostream& operator<<(std::ostream& os, const AForm& aform);

#endif