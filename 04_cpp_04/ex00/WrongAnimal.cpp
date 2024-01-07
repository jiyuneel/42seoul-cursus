#include "WrongAnimal.hpp"

/* Constructor */
WrongAnimal::WrongAnimal() {
    this->_type = "WrongAnimal";
    std::cout << "WrongAnimal constructed" << std::endl;
}

/* Copy constructor */
WrongAnimal::WrongAnimal(const WrongAnimal& animal) {
    *this = animal;
    std::cout << "WrongAnimal constructed" << std::endl;
}

/* Copy assignment operator */
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& animal) {
    if (this != &animal) {
        this->_type = animal.getType();
    }
    return *this;
}

/* Destructor */
WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destroyed" << std::endl;
}

const std::string& WrongAnimal::getType() const {
    return this->_type;
}

void WrongAnimal::makeSound() const {
    std::cout << "🙈 Aniya Aniya" << std::endl;
}