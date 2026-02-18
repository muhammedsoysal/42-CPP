#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *brain;

public:
	Cat();
	Cat(std::string type);
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	virtual ~Cat();

	// member functions
	virtual void makeSound() const;
	Brain* getBrain() const; // getter for brain (needed for testing)
};

#endif