#include "Zombie.hpp"

int main()
{
    
    Zombie* zombie1 = newZombie("SOYSAL");
    zombie1->announce();
    delete zombie1;
    randomChump("GOINFRE");

    return 0;
}

