
#include <iostream>

int main()
{
	// 1) Orijinal string (stack üzerinde)
	std::string str = "HI THIS IS BRAIN";

	// 2) Pointer: str'nin adresini tutar
	std::string *stringPTR = &str;

	// 3) Reference: str'nin bir takma adı (alias)
	std::string &stringREF = str;

	// --- Adresleri yazdırma ---
	std::cout << "Address of str:      " << &str << std::endl;
	std::cout << "Address held by PTR: " << stringPTR << std::endl;
	std::cout << "Address held by REF: " << &stringREF << std::endl;

	std::cout << std::endl;

	// --- Değerleri yazdırma ---
	std::cout << "Value of str:        " << str << std::endl;
	std::cout << "Value via PTR:       " << *stringPTR << std::endl;
	std::cout << "Value via REF:       " << stringREF << std::endl;
	return 0;
}