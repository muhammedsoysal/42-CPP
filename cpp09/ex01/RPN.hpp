#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <list>
#include <stdexcept>


class RPN
{
private:
    std::list<int> _list;
    std::string _expression;
    
public:
    RPN();
    RPN(std::string expression);
    ~RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
    int calculate();
	
	


    
};



#endif