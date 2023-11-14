#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int index;

    void searchAllContacts();
    void printContact(int index);
    bool isValidRange(int index);
    std::string truncateStr(std::string str);

public:
    PhoneBook();

    void addContact();
    void searchContact();
    void exit();
};

#endif