#include "Ice.hpp"
#include "ICharacter.hpp"

/* Constructor */
Ice::Ice() : AMateria("ice") {
    this->_type = "ice";
    // std::cout << "Ice constructed" << std::endl;
}
/* Copy constructor */
Ice::Ice(const Ice& ice) : AMateria("ice") {
    *this = ice;
    // std::cout << "Ice constructed" << std::endl;
}
/* Copy assignment operator */
Ice& Ice::operator=(const Ice& ice) {
    if (this != &ice) {
        this->_type = ice.getType();
    }
    return *this;
}
/* Destructor */
Ice::~Ice() {
    // std::cout << "Ice destroyed" << std::endl;
}

Ice* Ice::clone() const {
    return new Ice();
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " + target.getName() + " *" << std::endl;
}