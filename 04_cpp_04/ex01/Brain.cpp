#include "Brain.hpp"

/* Constructor */
Brain::Brain() {
    std::cout << "Brain constructed" << std::endl;
}
/* Copy constructor */
Brain::Brain(const Brain& brain) {
    *this = brain;
    std::cout << "Brain constructed" << std::endl;
}
/* Copy assignment operator */
Brain& Brain::operator=(const Brain& brain) {
    // if (this != &brain) {
    //     this->_type = animal.getType();
    // }
    return *this;
}
/* Destructor */
Brain::~Brain() {
    std::cout << "Brain destroyed" << std::endl;
}