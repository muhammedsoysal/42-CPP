 #include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alice", 42);
        Bureaucrat b(a);

        std::cout << a << std::endl;
        std::cout << b << std::endl;

        a.incrementGrade();
        std::cout << a << std::endl;

        a.decrementGrade();
        std::cout << a << std::endl;
        Bureaucrat c("SOYSAL", 325442);
        Bureaucrat d("SOYSAL2", 0);
        
        std::cout << c << std::endl; // This will throw an exception due to invalid grade
        std::cout << d << std::endl; // This will throw an exception due to invalid grade
        
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}