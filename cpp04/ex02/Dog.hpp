#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;

public:
	Dog();
	Dog(std::string type);
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	virtual ~Dog();

	// member functions
	virtual void makeSound() const;
	Brain* getBrain() const; // getter for brain (needed for testing)
};

#endif