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
    if (this != &brain) {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = brain.getIdea(i);
    }
    return *this;
}
/* Destructor */
Brain::~Brain() {
    std::cout << "Brain destroyed" << std::endl;
}

const std::string Brain::getIdea(int idx) const {
    if (idx < 0 || idx > 100)
        return "";
    return this->_ideas[idx];
}

void Brain::setIdea(const std::string idea, int idx) {
    if (idx < 0 || idx > 100)
        return ;
    this->_ideas[idx] = idea;
}