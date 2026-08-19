#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void) {
    int a = 2;
    int b = 3;
    
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "hello";
    std::string d = "world";
    
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    float f1 = 4.2f;
    float f2 = 2.4f;
    std::cout << "max(f1, f2) = " << ::max(f1, f2) << std::endl;
    
    return 0;
}
