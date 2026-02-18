#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->name = "Unknown";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}
FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = copy;
}
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}
void FragTrap::highFivesGuys(void)
{
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
	{
		std::cout << this->name << " is dead or has no energy" << std::endl;
		return;
	}
	std::cout << this->name << "a positive high-fives request" << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->name = copy.name;
		this->hitPoints = copy.hitPoints;
		this->energyPoints = copy.energyPoints;
		this->attackDamage = copy.attackDamage;
	}
	return *this;
}