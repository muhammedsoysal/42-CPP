#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
private:
    std::string FirstName;
    std::string LastName;
    std::string Nickname;
    std::string PhoneNumber;
    std::string DarkestSecret;

public:
    void setFirstName(const std::string &str);
    std::string getFirstName() const;

    void setLastName(const std::string &str);
    std::string getLastName() const;

    void setNickname(const std::string &str);
    std::string getNickname() const;

    void setPhoneNumber(const std::string &str);
    std::string getPhoneNumber() const;

    void setDarkestSecret(const std::string &str);
    std::string getDarkestSecret() const;
};

#endif
