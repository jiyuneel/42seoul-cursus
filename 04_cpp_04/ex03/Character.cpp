#include "Character.hpp"

/* Constructor */
Character::Character() {
    this->_name = "Default";
    this->_numOfMaterias = 0;
    this->_numOfTrash = 0;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    // std::cout << "Character constructed" << std::endl;
}
Character::Character(const std::string& name) {
    this->_name = name;
    this->_numOfMaterias = 0;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    // std::cout << "Character constructed" << std::endl;
}
/* Copy constructor */
Character::Character(const Character& character) {
    *this = character;
    // std::cout << "Character constructed" << std::endl;
}
/* Copy assignment operator */
Character& Character::operator=(const Character& character) {
    if (this != &character) {
        this->_name = character.getName();
        this->_numOfMaterias = character.getNumOfMaterias();
        for (int i = 0; i < 4; i++) {
            if (this->_inventory[i]) {
                delete this->_inventory[i];
                this->_inventory[i] = NULL;
            }
            if (character.getMateria(i))
                this->_inventory[i] = character.getMateria(i)->clone();
        }
    }
    return *this;
}
/* Destructor */
Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i])
            delete this->_inventory[i];
    }
    for (int i = 0; i < this->_numOfTrash; i++)
        delete this->_floor[i];
    // std::cout << "Character destroyed" << std::endl;
}

const std::string& Character::getName() const {
    return this->_name;
}
int Character::getNumOfMaterias() const {
    return this->_numOfMaterias;
}
AMateria* Character::getMateria(int idx) const {
    return this->_inventory[idx];
}

void Character::equip(AMateria* m) {
    if (this->_numOfMaterias == 4) {
        std::cout << "Can't equip Materia. Inventory is full." << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++) {
        if (!this->_inventory[i]) {
            this->_inventory[i] = m->clone();
            break ;
        }
    }
    this->_numOfMaterias++;
}

void Character::unequip(int idx) {
    if (this->_numOfMaterias == 0 || (idx < 0 || idx > 3)) {
        std::cout << "Can't unequip Materia. Materia does not exist." << std::endl;
        return ;
    }
    this->_floor[this->_numOfTrash++] = this->_inventory[idx];
    this->_inventory[idx] = NULL;
    this->_numOfMaterias--;
}

void Character::use(int idx, ICharacter& target) {
    if (this->_numOfMaterias == 0 || (idx < 0 || idx > 3) || !this->_inventory[idx]) {
        std::cout << "Can't use Materia. Materia does not exist." << std::endl;
        return ;
    }
    this->_inventory[idx]->use(target);
}