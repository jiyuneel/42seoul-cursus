#include "Animal.hpp"

/* Constructor */
Animal::Animal() {
    this->_type = "Animal";
    std::cout << "Animal constructed" << std::endl;
}

/* Copy constructor */
Animal::Animal(const Animal& animal) {
    *this = animal;
    std::cout << "Animal constructed" << std::endl;
}

/* Copy assignment operator */
Animal& Animal::operator=(const Animal& animal) {
    if (this != &animal) {
        this->_type = animal.getType();
    }
    return *this;
}

/* Destructor */
Animal::~Animal() {
    std::cout << "Animal destroyed" << std::endl;
}

const std::string& Animal::getType() const {
    return this->_type;
}

void Animal::makeSound() const {
    std::cout << "🐲 Ani  Ani" << std::endl;
}