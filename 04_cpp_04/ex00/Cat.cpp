#include "Cat.hpp"

/* Constructor */
Cat::Cat() : Animal() {
    this->_type = "Cat";
    std::cout << "Cat constructed" << std::endl;
}

/* Copy constructor */
Cat::Cat(const Cat& cat) : Animal() {
    *this = cat;
    std::cout << "Cat constructed" << std::endl;
}

/* Copy assignment operator */
Cat& Cat::operator=(const Cat& cat) {
    if (this != &cat) {
        this->_type = cat.getType();
    }
    return *this;
}

/* Destructor */
Cat::~Cat() {
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "🐱 Meow Meow" << std::endl;
}