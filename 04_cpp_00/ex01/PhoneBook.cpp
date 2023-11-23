#include "PhoneBook.hpp"
#include <iomanip>
#include <cstdio>
#include <sstream>

PhoneBook::PhoneBook() {
    this->index = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::handleEof() {
    std::clearerr(stdin);
    std::cin.clear();
    std::cout << std::endl;
}

void PhoneBook::addContact() {
    Contact contact;
    std::string input;

    std::cout << std::endl;
    while (contact.getFirstName().empty()) {
        std::cout << "First Name     : ";
        std::getline(std::cin, input);

        if (std::cin.eof()) {
            handleEof();
            return;
        }
        if (!input.empty())
            contact.setFirstName(input);
    }

    while (contact.getLastName().empty()) {
        std::cout << "Last Name      : ";
        std::getline(std::cin, input);

        if (std::cin.eof()) {
            handleEof();
            return;
        }
        if (!input.empty())
            contact.setLastName(input);
    }

    while (contact.getNickname().empty()) {
        std::cout << "Nickname       : ";
        std::getline(std::cin, input);

        if (std::cin.eof()) {
            handleEof();
            return;
        }
        if (!input.empty())
            contact.setNickname(input);
    }

    while (contact.getPhoneNumber().empty()) {
        std::cout << "Phone Number   : ";
        std::getline(std::cin, input);

        if (std::cin.eof()) {
            handleEof();
            return;
        }
        if (!input.empty())
            contact.setPhoneNumber(input);
    }

    while (contact.getDarkestSecret().empty()) {
        std::cout << "Darkest Secret : ";
        std::getline(std::cin, input);

        if (std::cin.eof()) {
            handleEof();
            return;
        }
        if (!input.empty())
            contact.setDarkestSecret(input);
    }
    std::cout << std::endl;

    this->contacts[this->index % 8] = contact;
    this->index++;
}

void PhoneBook::searchContact() {
    std::cout << std::endl;
    printAllContacts();

    std::string indexStr;
    std::cout << "Index          : ";
    std::getline(std::cin, indexStr);

    if (std::cin.eof()) {
        handleEof();
        return;
    }
    for (unsigned int i = 0; i < indexStr.length(); i++) {
        if (!isdigit(indexStr[i])) {
            std::cout << "[ERROR] Invalid Input" << std::endl;
            return;
        }
    }

    int index;
    std::stringstream ss(indexStr);
    ss >> index;
    if (this->index >= index && (1 <= index && index <= 8)) {
        std::cout << "First Name     : " << contacts[index - 1].getFirstName() << std::endl;
        std::cout << "Last Name      : " << contacts[index - 1].getLastName() << std::endl;
        std::cout << "Nickname       : " << contacts[index - 1].getNickname() << std::endl;
        std::cout << "Phone Number   : " << contacts[index - 1].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret : " << contacts[index - 1].getDarkestSecret() << std::endl;
    }
    else
        std::cout << "[ERROR] Invalid Index" << std::endl;
    std::cout << std::endl;
}

void PhoneBook::printAllContacts() {
    std::cout << std::setw(10) << std::right << "Index" << "|";
    std::cout << std::setw(10) << std::right << "First Name" << "|";
    std::cout << std::setw(10) << std::right << "Last Name" << "|";
    std::cout << std::setw(10) << std::right << "Nickame" << std::endl;
    std::cout << "----------+----------+----------+----------" << std::endl;

    int n = index <= 8 ? index : 8;
    for (int i = 0; i < n; i++) {
        std::cout << std::setw(10) << std::right << i + 1 << "|";
        std::cout << std::setw(10) << std::right << truncateStr(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << std::right << truncateStr(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << std::right << truncateStr(contacts[i].getNickname()) << std::endl;
    }
    std::cout << std::endl;
}

std::string PhoneBook::truncateStr(std::string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}