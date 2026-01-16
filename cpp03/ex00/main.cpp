#include "ClapTrap.hpp"

int main(void)
{

	ClapTrap cp("Soysal");
	// attack test
	cp.attack("Enemy");
	cp.attack("Monster");

	cp.beRepaired(5);
	cp.beRepaired(3);

	cp.takeDamage(8);
	cp.takeDamage(15);

	return 0;
}