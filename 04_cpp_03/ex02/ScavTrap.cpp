#include "ScavTrap.hpp"

/* Constructor */
ScavTrap::ScavTrap() : ClapTrap("Default") {
    this->_name = "Default";
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap constructed" << std::endl;
}
ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
    this->_name = name;
    this->_hitPoint = 100;
    this->_energyPoint = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " + this->_name + " constructed" << std::endl;
}

/* Copy constructor */
ScavTrap::ScavTrap(const ScavTrap& scavTrap) {
    *this = scavTrap;
}

/* Copy assignment operator */
ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap) {
    if (this != &scavTrap) {
        this->_name = scavTrap.getName();
        this->_hitPoint = scavTrap.getHitPoint();
        this->_energyPoint = scavTrap.getEnergyPoint();
        this->_attackDamage = scavTrap.getAttackDamage();
        std::cout << "ScavTrap " + this->_name + " constructed" << std::endl;
    }
    return *this;
}

/* Destructor */
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " + this->_name + " destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->_hitPoint <= 0 || this->_energyPoint <= 0) {
        std::cout << this->_name << " can't do anything" << std::endl;
        return ;
    }
    this->_energyPoint--;
    std::cout << "ScavTrap " + this->_name + " attacks " + target + "!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << this->_name + " is now in Gatekeeper mode." << std::endl;
}