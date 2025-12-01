
#include "Harl.hpp"

int main()
{
	std::string levels[4] = {"debug", "info", "warning", "error"};

	Harl harl;
	std::cout << "------ DEBUG ------" << std::endl;
	harl.complain("debug");

	std::cout << "------ INFO ------" << std::endl;
	harl.complain("info");

	std::cout << "------ WARNING ------" << std::endl;
	harl.complain("warning");

	std::cout << "------ ERROR ------" << std::endl;
	harl.complain("error");
	return 0;
}