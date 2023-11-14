#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook() {
    this->index = 0;
}

void PhoneBook::addContact() {
    Contact contact;
    contact.enterInformation();
    this->contacts[this->index % 8] = contact;
    this->index++;
}

void PhoneBook::searchContact() {
    searchAllContacts();

    std::string index;
    std::cout << "Index  : ";
    std::getline(std::cin, index);
    // std::cin >> index;
    // std::cin.ignore();
    if (isValidRange(std::stoi(index))) {
        printContact(std::stoi(index) - 1);
    }
    else {
        std::cout << "[ERROR] Invalid Index" << std::endl;
    }
    std::cout << std::endl;
}

void PhoneBook::searchAllContacts() {
    std::cout << std::setw(10) << std::right << "Index" << "|";
    std::cout << std::setw(10) << std::right << "First Name" << "|";
    std::cout << std::setw(10) << std::right << "Last Name" << "|";
    std::cout << std::setw(10) << std::right << "Nickame" << std::endl;
    std::cout << "----------+----------+----------+----------" << std::endl;

    if (index <= 8) {
        for (int i = 0; i < index; i++)
            printContact(i);
    }
    else {
        for (int i = 0; i < 8; i++)
            printContact(i);
    }
    std::cout << std::endl;
}

void PhoneBook::printContact(int index) {
    std::cout << std::setw(10) << std::right << index + 1 << "|";
    std::cout << std::setw(10) << std::right << truncateStr(contacts[index].getFirstName()) << "|";
    std::cout << std::setw(10) << std::right << truncateStr(contacts[index].getLastName()) << "|";
    std::cout << std::setw(10) << std::right << truncateStr(contacts[index].getNickname()) << std::endl;
}

bool PhoneBook::isValidRange(int index) {
    if (this->index >= index && (1 <= index && index <= 8))
        return true;
    return false;
}

std::string PhoneBook::truncateStr(std::string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::exit() {

}