#include "Contact.hpp"

std::string Contact::getFirstName() {
    return firstName;
}
std::string Contact::getLastName() {
    return lastName;
}
std::string Contact::getNickname() {
    return nickname;
}
std::string Contact::getPhoneNumber() {
    return phoneNumber;
}
std::string Contact::getSecret() {
    return secret;
}

void Contact::setFirstName(std::string firstName) {
    this->firstName = firstName;
}
void Contact::setLastName(std::string lastName) {
    this->lastName = lastName;
}
void Contact::setNickname(std::string nickname) {
    this->nickname = nickname;
}
void Contact::setPhoneNumber(std::string phoneNumber) {
    this->phoneNumber = phoneNumber;
}
void Contact::setSecret(std::string secret) {
    this->secret = secret;
}

void Contact::enterInformation() {
    std::cout << "First Name     : ";
    std::getline(std::cin, this->firstName);

    std::cout << "Last Name      : ";
    std::getline(std::cin, this->lastName);

    std::cout << "Nickame        : ";
    std::getline(std::cin, this->nickname);

    std::cout << "Phone Number   : ";
    std::getline(std::cin, this->phoneNumber);

    std::cout << "Darkest Secret : ";
    std::getline(std::cin, this->secret);

    std::cout << std::endl;
}