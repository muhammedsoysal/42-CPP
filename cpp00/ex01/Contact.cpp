#include "Contact.hpp"

std::string	Contact::getFirstName() const
{
	return FirstName;
}
void	Contact::setFirstName(const std::string& str)
{
	FirstName = str;
}
std::string	Contact::getLastName() const
{
	return LastName;
}
void	Contact::setLastName(const std::string& str)
{
	LastName = str;
}
std::string	Contact::getNickname() const
{
	return Nickname;
}
void	Contact::setNickname(const std::string& str)
{
	Nickname = str;
}
std::string	Contact::getPhoneNumber() const
{
	return PhoneNumber;
}
void	Contact::setPhoneNumber(const std::string& str)
{
	PhoneNumber = str;
}
std::string	Contact::getDarkestSecret() const
{
	return DarkestSecret;
}
void	Contact::setDarkestSecret(const std::string& str)
{
	DarkestSecret = str;
}
