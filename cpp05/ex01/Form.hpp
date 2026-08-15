#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    Form();    
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& copy);
    ~Form();

    void    beSigned(Bureaucrat& b);

    std::string getName(void) const;
    int         getGradeToSign(void) const;
    int         getGradeToExecute(void) const;
    bool        getIsSigned(void) const;

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

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif