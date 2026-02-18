#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Default")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}
void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makeSound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (_type);
}
