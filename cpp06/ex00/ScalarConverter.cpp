#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
{

}
ScalarConverter::~ScalarConverter() 
{

}
ScalarConverter::ScalarConverter(const ScalarConverter& other) 
{
    (void)other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) 
{
    (void)other;
    return *this;
}

bool specialCase(const std::string& arg)
{
    if (arg == "nan" || arg == "nanf") // DİKKAT: '=' yerine '==' olmalıydı!
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl; // float için sonunda f olması iyi olur
        std::cout << "double: nan" << std::endl;
        return true;
    }
    if (arg == "+inf" || arg == "+inff" || arg == "inf" || arg == "inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return true;
    }
    if (arg == "-inf" || arg == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return true;
    }
    return false;
}

void printChar(double val)
{
    if (val > CHAR_MAX || val < CHAR_MIN || std::isnan(val) || std::isinf(val))
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(val);
    if (isprint(c))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: Non-displayable" << std::endl;
}

void printInt(double val)
{
    if (val > (double)INT_MAX || val < (double)INT_MIN || std::isnan(val) || std::isinf(val))
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    int i = static_cast<int>(val);
    std::cout << "int: " << static_cast<int>(i) << std::endl;
}

void printFloat(double val)
{
    float f_val = static_cast<float>(val);
    if (!std::isnan(f_val) && !std::isinf(f_val) && std::floor(f_val) == f_val)
    {
        std::cout << "float: " << std::fixed << std::setprecision(1) << f_val << "f" << std::endl;
    }
    else
        std::cout << "float: " << f_val << "f" << std::endl;
}

void printDouble(double val)
{
    if (!std::isnan(val) && !std::isinf(val) && std::floor(val) == val)
        std::cout << "double: " << std::fixed << std::setprecision(1) << val << std::endl;
    else
        std::cout << "double: " << val << std::endl;
}

void ScalarConverter::convert(const std::string& arg)
{
    if (specialCase(arg))
        return;
    std::string inp = arg;
    // Eğer string 1 karakterden uzunsa, sonunda 'f' varsa ve içinde '.' geçiyorsa (Yani float ise: 42.0f)
    if (inp.length() > 1 && inp[inp.length() - 1] == 'f' && inp.find('.') != std::string::npos)
        inp.erase(inp.length() - 1); // Sondaki 'f' harfini sil (Sayıya çevirirken hata vermesin diye)

    double value = 0.0;
    std::stringstream ss(inp);
    ss >> value;

    // Eğer sayıya çevirme işlemi başarısız olduysa VE tek bir karakter ('a' gibi) değilse:
    if (ss.fail() && arg.length() != 1)
    {
        std::cerr << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
        return;
    }
    
    // Eğer sayıya çevrilemediyse ama tek karakterse (örneğin 'a' harfi geldiyse)
    if (ss.fail() && arg.length() == 1 && !isdigit(arg[0])) 
    {
        value = static_cast<double>(arg[0]); // 'a' harfinin ASCII değeri olan 97'yi double olarak value içine koy!
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
    
}

    