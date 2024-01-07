#include "WrongCat.hpp"

/* Constructor */
WrongCat::WrongCat() : WrongAnimal() {
    this->_type = "WrongCat";
    std::cout << "WrongCat constructed" << std::endl;
}
/* Copy constructor */
WrongCat::WrongCat(const WrongCat& cat) : WrongAnimal() {
    *this = cat;
    std::cout << "WrongCat constructed" << std::endl;
}
/* Copy assignment operator */
WrongCat& WrongCat::operator=(const WrongCat& cat) {
    if (this != &cat) {
        this->_type = cat.getType();
    }
    return *this;
}
/* Destructor */
WrongCat::~WrongCat() {
    std::cout << "WrongCat destroyed" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "🙈 Meom Meom" << std::endl;
}