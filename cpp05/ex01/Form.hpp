#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class   Form : public Bureaucrat
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

}
#endif