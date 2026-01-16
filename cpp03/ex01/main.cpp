#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main(void)
{
	std::cout << "ScavTrap test" << std::endl;
	ScavTrap st("Soysal");
	st.guardGate();
	st.attack("Enemy");
	st.beRepaired(10);
	st.takeDamage(30);
	st.takeDamage(50);
	st.guardGate();
	st.attack("Robot");
	st.beRepaired(10);
	st.takeDamage(30);
	st.takeDamage(50);
	return 0;
}