#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade; // 1 (en yüksek) ile 150 (en düşük) arasında bir değer alır
public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& copy);
    ~Bureaucrat();

    int getGrade() const;
    std::string getName() const;

    // Rütbe değiştirme fonksiyonları
    void incrementGrade(); // Rütbeyi 1 artırır (sayısal olarak azaltır)
    void decrementGrade(); // Rütbeyi 1 azaltır (sayısal olarak artırır)    
   
    void signForm(AForm& aform);
    void executeForm(AForm const & form);

    // İç içe Hata (Exception) Sınıfları
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
#endif