#include "RPN.hpp"
#include <cstddef>
#include <iostream>
#include <stdexcept>

RPN::RPN()
{
	this->_expression = "";
}

RPN::RPN(std::string expression)
{
	this->_expression = expression;
}

RPN::~RPN()
{
	this->_list.clear();
}

RPN::RPN(const RPN& other)
{
	this->_expression = other._expression;
	this->_list = other._list;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this->_expression = other._expression;
		this->_list = other._list;
	}
	return *this;
}

int RPN::calculate()
{

	for (size_t i = 0; i < _expression.length(); i++)
	{
		char c = _expression[i];
		if (c == ' ')
			continue;
		if (std::isdigit(c) && (i + 1 == _expression.length() || _expression[i + 1] == ' '))
		{
			_list.push_back(c - '0');
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (_list.size()<2)
				throw std::runtime_error("Error");

			int num1 = _list.back();
			_list.pop_back();
			int num2 = _list.back();
			_list.pop_back();
			
			if (c=='+')
				_list.push_back(num1 + num2);
			else if (c=='*')
				_list.push_back(num1 * num2);
			else if (c=='-')
				_list.push_back(num2 - num1);
			else if (c=='/')
			{
				if (num1== 0)
					throw std::runtime_error("Error");
				_list.push_back(num2 / num1);
			}
		}
		else
			throw std::runtime_error("Error");
	}
	if (_list.size() != 1)
		throw std::runtime_error("Error");
	return _list.front();
}
