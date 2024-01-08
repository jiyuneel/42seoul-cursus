#include "Cat.hpp"

/* Constructor */
Cat::Cat() : Animal() {
    this->_type = "Cat";
    this->_brain = new Brain();
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
        this->_brain = new Brain(*cat.getBrain());
    }
    return *this;
}
/* Destructor */
Cat::~Cat() {
    delete this->_brain;
    std::cout << "Cat destroyed" << std::endl;
}

Brain* Cat::getBrain() const {
    return this->_brain;
}

void Cat::makeSound() const {
    std::cout << "🐱 Meow Meow" << std::endl;
}