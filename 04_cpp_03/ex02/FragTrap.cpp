#include "FragTrap.hpp"

/* Constructor */
FragTrap::FragTrap() : ClapTrap() {
    this->_name = "Default";
    this->_hitPoint = 100;
    this->_energyPoint = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " + this->_name + " constructed" << std::endl;
}
FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
    this->_name = name;
    this->_hitPoint = 100;
    this->_energyPoint = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " + this->_name + " constructed" << std::endl;
}

/* Copy constructor */
FragTrap::FragTrap(const FragTrap& fragTrap) : ClapTrap() {
    *this = fragTrap;
    std::cout << "FragTrap " + this->_name + " constructed" << std::endl;
}

/* Copy assignment operator */
FragTrap& FragTrap::operator=(const FragTrap& fragTrap) {
    if (this != &fragTrap) {
        this->_name = fragTrap.getName();
        this->_hitPoint = fragTrap.getHitPoint();
        this->_energyPoint = fragTrap.getEnergyPoint();
        this->_attackDamage = fragTrap.getAttackDamage();
        std::cout << "FragTrap copy assignment operator called" << std::endl;
    }
    return *this;
}

/* Destructor */
FragTrap::~FragTrap() {
    std::cout << "FragTrap " + this->_name + " destroyed" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << this->_name + " high five!" << std::endl;
}