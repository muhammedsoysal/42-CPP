#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap ct("Clappy");
	ScavTrap st("Soysal");

	ct.attack("Enemy");
	st.attack("Enemy");
	st.guardGate();
	st.takeDamage(80);
	st.beRepaired(20);
	st.takeDamage(50);
	st.attack("Ghost");

	return 0;
}