#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	void addContact(PhoneBook &phoneBook);
	void searchContact(int index) const;
	std::string getInput(const std::string &prompt) const;

private:
	Contact contacts[8];
	int contactCount;
	std::string formatField(const std::string &field) const;
};
#endif