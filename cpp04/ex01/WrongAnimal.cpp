#include "WrongAnimal.hpp"

// constructors
WrongAnimal::WrongAnimal() : _type("Default")
{
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal (std::string type) : _type(type)
{
	std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type)
{
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	_type = other._type;
	std::cout << "WrongAnimal copy assignment constructor called\n";
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal deconstructor called\n";
}


// member functions
void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal could make several different sounds\n";
}

std::string WrongAnimal::getType() const
{
	return (_type);
}
