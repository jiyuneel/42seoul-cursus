#include "Dog.hpp"

/* Constructor */
Dog::Dog() : Animal() {
    this->_type = "Dog";
    std::cout << "Dog constructed" << std::endl;
}

/* Copy constructor */
Dog::Dog(const Dog& dog) : Animal() {
    *this = dog;
    std::cout << "Dog constructed" << std::endl;
}

/* Copy assignment operator */
Dog& Dog::operator=(const Dog& dog) {
    if (this != &dog) {
        this->_type = dog.getType();
    }
    return *this;
}

/* Destructor */
Dog::~Dog() {
    std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "🐶 Woof Woof" << std::endl;
}