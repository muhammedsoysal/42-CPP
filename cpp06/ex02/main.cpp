#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>



Base *generate(void)
{
    Base *ptr;

    srand(time(NULL));
    int random = rand() % 3;
    
    if (random == 0)
    {
        ptr = new A();
        std::cout << "Class A is generated" << std::endl;
    }
    else if (random == 1)
    {
        ptr = new B();
        std::cout << "Class B is generated" << std::endl;
    }
    else
    {
        ptr = new C();
        std::cout << "Class C is generated" << std::endl;
    }
    return ptr;
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Class A is identified" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Class B is identified" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Class C is identified" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;    
        std::cout << "Class A is identified" << std::endl;
    }
    catch (const std::exception &e) { (void)e; }
    try
    {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "Class B is identified" << std::endl;
    }
    catch (const std::exception &e) { (void)e; }
    try
    {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "Class C is identified" << std::endl;
    }
    catch (const std::exception &e) { (void)e; }
}

int main()
{
    Base *instance = generate();
    identify(*instance);
    identify(instance);
    
    delete instance; // Hafiza sizintisini (Memory Leak) onlemek icin ekledik
    return 0;
}