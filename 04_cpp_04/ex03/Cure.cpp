#include "Cure.hpp"
#include "ICharacter.hpp"

/* Constructor */
Cure::Cure() : AMateria("cure") {
    this->_type = "cure";
    // std::cout << "Cure constructed" << std::endl;
}
/* Copy constructor */
Cure::Cure(const Cure& cure) : AMateria("cure") {
    *this = cure;
    // std::cout << "Cure constructed" << std::endl;
}
/* Copy assignment operator */
Cure& Cure::operator=(const Cure& cure) {
    if (this != &cure) {
        this->_type = cure.getType();
    }
    return *this;
}
/* Destructor */
Cure::~Cure() {
    // std::cout << "Cure destroyed" << std::endl;
}

Cure* Cure::clone() const {
    return new Cure();
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " + target.getName() + "’s wounds *" << std::endl;
}