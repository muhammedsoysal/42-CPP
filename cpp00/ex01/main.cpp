#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string command;
	while (1)
	{
		command = phoneBook.getInput("Enter a command (ADD, SEARCH, EXIT): ");
		if (command == "ADD")
			phoneBook.addContact(phoneBook);
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return 0;
}
