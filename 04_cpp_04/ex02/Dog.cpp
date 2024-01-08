#include "Dog.hpp"

/* Constructor */
Dog::Dog() : Animal() {
    this->_type = "Dog";
    this->_brain = new Brain();
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
        this->_brain = new Brain(*dog.getBrain());
    }
    return *this;
}
/* Destructor */
Dog::~Dog() {
    delete this->_brain;
    std::cout << "Dog destroyed" << std::endl;
}

Brain* Dog::getBrain() const {
    return this->_brain;
}

void Dog::makeSound() const {
    std::cout << "🐶 Woof Woof" << std::endl;
}