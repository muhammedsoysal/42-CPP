#include "FragTrap.hpp"

int main(void)
{
	FragTrap frag("Soysal");
	frag.attack("bad guy");
	frag.takeDamage(40);
	frag.beRepaired(20);
	frag.highFivesGuys();

	return 0;
}