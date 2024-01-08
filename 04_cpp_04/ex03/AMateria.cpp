#include "AMateria.hpp"

/* Constructor */
AMateria::AMateria() {
    this->_type = "Materia";
    // std::cout << "AMateria constructed" << std::endl;
}
AMateria::AMateria(const std::string& type) {
    this->_type = type;
    // std::cout << "AMateria constructed" << std::endl;
}
/* Copy constructor */
AMateria::AMateria(const AMateria& aMateria) {
    *this = aMateria;
    // std::cout << "AMateria constructed" << std::endl;
}
/* Copy assignment operator */
AMateria& AMateria::operator=(const AMateria& aMateria) {
    if (this != &aMateria) {
        this->_type = aMateria.getType();
    }
    return *this;
}
/* Destructor */
AMateria::~AMateria() {
    // std::cout << "AMateria destroyed" << std::endl;
}

const std::string& AMateria::getType() const {
    return this->_type;
}

void AMateria::use(ICharacter& target) {
    (void) target;
}