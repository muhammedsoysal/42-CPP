#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip> 
#include <cstdlib> 
#include <climits> 
#include <cctype>  


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &str) {
  
    if (str == "nan" || str == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }
    if (str == "-inf" || str == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }
    if (str.length() == 1 && !std::isdigit(static_cast<unsigned char>(str[0]))) {
        char c = str[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
        return;
    }

    char *endptr = NULL;
    double d = std::strtod(str.c_str(), &endptr);

    if (endptr == str.c_str() || (*endptr != '\0' && !((*endptr == 'f' || *endptr == 'F') && *(endptr + 1) == '\0'))) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    if (d < CHAR_MIN || d > CHAR_MAX || d != d) {
        std::cout << "char: impossible" << std::endl;
    } else {
        char c = static_cast<char>(d);
        if (std::isprint(static_cast<unsigned char>(c)))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }

    if (d < INT_MIN || d > INT_MAX || d != d) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    }
    float f = static_cast<float>(d);
    if (d == static_cast<int>(d) && d >= INT_MIN && d <= INT_MAX) {
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    } else {
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
}