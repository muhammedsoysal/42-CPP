#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
	this->name = name;
	std::cout << this->name << " Zombie constructor called" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " Zombie destructor called" << std::endl;
}

void Zombie::announce()
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}