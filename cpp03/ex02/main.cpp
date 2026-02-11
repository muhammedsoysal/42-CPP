#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap ct("Clappy");
	ScavTrap st("Scavy");
	FragTrap ft("Fraggy");

	ct.attack("Enemy");
	st.attack("Enemy");
	ft.attack("Enemy");

	ft.highFivesGuys();
	st.guardGate();

	ft.takeDamage(80);
	ft.beRepaired(30);
	ft.takeDamage(60);
	ft.attack("Ghost");

	return 0;
}