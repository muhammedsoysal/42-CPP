#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// Array of Animals (polymorphism + no leak)
	{
		const int N = 6;
		Animal* animals[N];

		for (int k = 0; k < N; ++k)
		{
			if (k % 2 == 0)
				animals[k] = new Dog();
			else
				animals[k] = new Cat();
		}

		for (int k = 0; k < N; ++k)
			animals[k]->makeSound();

		for (int k = 0; k < N; ++k)
			delete animals[k];
	}

	// Deep copy test (Dog)
	{
		Dog original;
		original.getBrain()->ideas[0] = "original  idea dog";

		Dog copy(original);
		copy.getBrain()->ideas[0] = "copy idea dog";

		std::cout << original.getBrain()->ideas[0] << std::endl;
		std::cout << copy.getBrain()->ideas[0] << std::endl;
	}

	// Deep copy test (Cat)
	{
		Cat original;
		original.getBrain()->ideas[0] = "original idea cat";

		Cat copy(original);
		copy.getBrain()->ideas[0] = "copy idea cat";

		std::cout << original.getBrain()->ideas[0] << std::endl;
		std::cout << copy.getBrain()->ideas[0] << std::endl;
	}

	return 0;
}
