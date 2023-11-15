#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int index;

    void handleEof();
    void printAllContacts();
    std::string truncateStr(std::string str);

public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void searchContact();
};

#endif