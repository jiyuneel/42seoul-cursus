#include "MateriaSource.hpp"

/* Constructor */
MateriaSource::MateriaSource() {
    this->_numOfMaterias = 0;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    // std::cout << "MateriaSource constructed" << std::endl;
}
/* Copy constructor */
MateriaSource::MateriaSource(const MateriaSource& materiaSource) {
    *this = materiaSource;
    // std::cout << "MateriaSource constructed" << std::endl;
}
/* Copy assignment operator */
MateriaSource& MateriaSource::operator=(const MateriaSource& materiaSource) {
    if (this != &materiaSource) {
        this->_numOfMaterias = materiaSource.getNumOfMaterias();
        for (int i = 0; i < 4; i++) {
            if (this->_inventory[i]) {
                delete this->_inventory[i];
                this->_inventory[i] = NULL;
            }
            if (materiaSource.getMateria(i))
                this->_inventory[i] = materiaSource.getMateria(i)->clone();
        }
    }
    return *this;
}
/* Destructor */
MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i])
            delete this->_inventory[i];
    }
    // std::cout << "MateriaSource destroyed" << std::endl;
}

int MateriaSource::getNumOfMaterias() const {
    return this->_numOfMaterias;
}
AMateria* MateriaSource::getMateria(int idx) const {
    return this->_inventory[idx];
}


void MateriaSource::learnMateria(AMateria* materia) {
    if (this->_numOfMaterias == 4) {
        delete materia;
        std::cout << "Can't learn Materia. Inventory is full." << std::endl;
        return ;
    }
    this->_inventory[this->_numOfMaterias++] = materia;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i]->getType() == type)
            return this->_inventory[i]->clone();
    }
    return 0;
}