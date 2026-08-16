 #include "Bureaucrat.hpp"

int main()
{
    
    try
    {
        Bureaucrat a("Alice", 2);
        Bureaucrat b(a);

        std::cout << a << std::endl;
        std::cout << b << std::endl;

        a.incrementGrade();
        std::cout << a << std::endl;

        a.decrementGrade();
        std::cout << a << std::endl;
        
        Bureaucrat c("SOYSAL", 150);
        c.incrementGrade();
        std::cout << c << std::endl;
        c.decrementGrade();
        c.decrementGrade(); 
        
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}