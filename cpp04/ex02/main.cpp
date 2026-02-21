#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// Array of Animals (polymorphism + abstract class test)
	{
		const int N = 4;
		Animal* animals[N];

		for (int i = 0; i < N; i++)
		{
			if (i % 2 == 0)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		for (int i = 0; i < N; i++)
			animals[i]->makeSound();

		for (int i = 0; i < N; i++)
			delete animals[i];
	}

	return 0;
}
