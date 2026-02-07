#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "===== Subject test (no leak) =====" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << "j type: " << j->getType() << std::endl;
		std::cout << "i type: " << i->getType() << std::endl;
		j->makeSound();
		i->makeSound();

		delete j; // should not create a leak
		delete i;
	}

	std::cout << std::endl;
	std::cout << "===== Array of Animals (half Dog, half Cat) =====" << std::endl;
	{
		const int N = 6;
		Animal* animals[N];

		for (int i = 0; i < N / 2; i++)
			animals[i] = new Dog();
		for (int i = N / 2; i < N; i++)
			animals[i] = new Cat();

		for (int i = 0; i < N; i++)
		{
			std::cout << "[" << i << "] " << animals[i]->getType() << " ";
			animals[i]->makeSound();
		}

		for (int i = 0; i < N; i++)
			delete animals[i];
	}

	// Deep copy = kopyalarken yeni bir Brain oluşturup içeriği kopyalamak.
	// Shallow olsaydı: original.brain ve copy.brain AYNI adresi gösterir;
	//   birinde ideas[0] değişince diğeri de değişir.
	// Deep olunca: her birinin kendi Brain'i var; birini değiştirince diğeri etkilenmez.
	std::cout << std::endl;
	std::cout << "===== Deep copy test (Dog) =====" << std::endl;
	{
		Dog original;
		original.brain->ideas[0] = "ben orijinalin fikri";

		Dog copy(original); // kopya al

		copy.brain->ideas[0] = "ben kopyanin fikri"; // sadece kopyanin fikrini degistir

		std::cout << "Original dog'un 1. fikri: " << original.brain->ideas[0] << std::endl;
		std::cout << "Copy dog'un 1. fikri:     " << copy.brain->ideas[0] << std::endl;
		// Deep copy ise: ustte "ben orijinalin fikri", altta "ben kopyanin fikri" gorunur.
		// Shallow copy ise: ikisi de "ben kopyanin fikri" olur (aynı Brain paylasiliyor).
	}

	std::cout << std::endl;
	std::cout << "===== Deep copy test (Cat) =====" << std::endl;
	{
		Cat original;
		original.brain->ideas[0] = "orijinal kedinin fikri";

		Cat copy(original);

		copy.brain->ideas[0] = "kopya kedinin fikri";

		std::cout << "Original cat'in 1. fikri: " << original.brain->ideas[0] << std::endl;
		std::cout << "Copy cat'in 1. fikri:     " << copy.brain->ideas[0] << std::endl;
	}

	return 0;
}
