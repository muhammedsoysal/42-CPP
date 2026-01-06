
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	// --- Write addresses ---
	std::cout << "Address of str:      " << &str << std::endl;
	std::cout << "Address held by PTR: " << stringPTR << std::endl;
	std::cout << "Address held by REF: " << &stringREF << std::endl;

	std::cout << std::endl;

	// --- Write values ---
	std::cout << "Value of str:        " << str << std::endl;
	std::cout << "Value via PTR:       " << *stringPTR << std::endl;
	std::cout << "Value via REF:       " << stringREF << std::endl;
	
	return 0;
}