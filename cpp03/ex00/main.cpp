#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap cp("Soysal");

	cp.attack("Enemy");
	cp.takeDamage(5);
	cp.beRepaired(3);
	cp.takeDamage(20);
	cp.attack("Ghost");
	cp.beRepaired(10);

	return 0;
}