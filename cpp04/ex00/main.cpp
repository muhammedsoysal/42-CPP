#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "===== Correct polymorphism (Animal) =====" << std::endl;
    {
        const Animal* meta = new Animal();

        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << "j type: " << j->getType() << std::endl; // Dog
        std::cout << "i type: " << i->getType() << std::endl; // Cat

        std::cout << "i->makeSound(): ";
        i->makeSound();  // Cat sound (correct, virtual means)

        std::cout << "j->makeSound(): ";
        j->makeSound();   // Dog sound (correct)

        std::cout << "meta->makeSound(): ";
        meta->makeSound();// Animal sound

        delete i;
        delete j;
        delete meta;
    }

    std::cout << std::endl;
    std::cout << "===== Wrong polymorphism (WrongAnimal) =====" << std::endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();

        std::cout << "i type: " << i->getType() << std::endl; // WrongCat
        std::cout << "meta type: " << meta->getType() << std::endl; // Default

        std::cout << "i->makeSound(): ";
        i->makeSound();   			// Expected: cat sound (correct, virtual means)
									// Real: WrongAnimal sound (because virtual is not)
                                    
        std::cout << "meta->makeSound(): ";
        meta->makeSound();// WrongAnimal sound (correct)

        delete i;
        delete meta;
    }

    return 0;
}