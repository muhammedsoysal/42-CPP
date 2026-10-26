    #include <iostream>
    #include <vector>
    #include <list>
    #include "easyfind.hpp"

    int main()
    {
        std::vector<int> vec;
        for (int i = 0; i < 5; i++)
            vec.push_back(i * 10);

        try 
        {
            std::vector<int>::iterator it = easyfind(vec, 30);
            std::cout << *it << std::endl;
            easyfind(vec, 99);
        } 
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "--------------------" << std::endl;

        std::list<int> lst;
        for (int i = 1; i <= 3; i++)
            lst.push_back(i * 42);        
        try
        {
            std::list<int>::iterator it = easyfind(lst, 42);
            std::cout << *it << std::endl;
            easyfind(lst, 500);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        return 0;
    }
