#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "===== Abstract Class: Animal cannot be instantiated =====" << std::endl;
	std::cout << "Animal is now abstract (pure virtual makeSound() = 0)" << std::endl;
	std::cout << "This would cause compilation error: new Animal()" << std::endl;
	std::cout << std::endl;

	std::cout << "===== Polymorphism through Animal* pointers =====" << std::endl;
	{
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		std::cout << dog->getType() << " says: ";
		dog->makeSound();
		std::cout << cat->getType() << " says: ";
		cat->makeSound();

		delete dog;
		delete cat;
	}

	std::cout << std::endl;
	std::cout << "===== Array of Animals (polymorphism) =====" << std::endl;
	{
		const int N = 4;
		Animal* animals[N];

		animals[0] = new Dog();
		animals[1] = new Cat();
		animals[2] = new Dog();
		animals[3] = new Cat();

		for (int i = 0; i < N; i++)
		{
			std::cout << "Animal[" << i << "] (" << animals[i]->getType() << "): ";
			animals[i]->makeSound();
		}

		for (int i = 0; i < N; i++)
			delete animals[i];
	}

	std::cout << std::endl;
	std::cout << "===== Summary =====" << std::endl;
	std::cout << "✓ Animal is abstract: cannot create Animal objects" << std::endl;
	std::cout << "✓ Polymorphism works: Animal* can point to Dog/Cat" << std::endl;
	std::cout << "✓ Virtual destructors ensure proper cleanup" << std::endl;

	return 0;
}
