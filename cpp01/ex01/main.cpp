#include "Zombie.hpp"


int main()
{
	Zombie *zombie = zombieHorde(10, "Zombie");
	for (int i = 0; i < 10; i++)
		zombie[i].announce();
	delete[] zombie;
	return 0;
}
