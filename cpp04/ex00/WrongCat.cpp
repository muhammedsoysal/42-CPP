/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:21:10 by cgodecke          #+#    #+#             */
/*   Updated: 2023/10/20 12:30:35 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// constructors
WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat (std::string type) : WrongAnimal(type)
{
	_type = type;
	std::cout << "WrongCat constructor called\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	*this = other;
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	_type = other._type;
	std::cout << "WrongCat copy assignment constructor called\n";
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat deconstructor called\n";
}


// member functions
void WrongCat::makeSound() const
{
	std::cout << "WrongCat Miau Miau Miau\n";
}