#include "ClapTrap.hpp"

/* Constructor */
ClapTrap::ClapTrap() : _name("Default"), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
    std::cout << "ClapTrap constructed" << std::endl;
}
ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
    std::cout << "ClapTrap " + this->_name + " constructed" << std::endl;
}

/* Copy constructor */
ClapTrap::ClapTrap(const ClapTrap& clapTrap) {
    *this = clapTrap;
    std::cout << "ClapTrap " + this->_name + " constructed" << std::endl;
}

/* Copy assignment operator */
ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap) {
    if (this != &clapTrap) {
        this->_name = clapTrap.getName();
        this->_hitPoint = clapTrap.getHitPoint();
        this->_energyPoint = clapTrap.getEnergyPoint();
        this->_attackDamage = clapTrap.getAttackDamage();
        std::cout << "ClapTrap " + this->_name + " constructed" << std::endl;
    }
    return *this;
}

/* Destructor */
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " + this->_name + " destroyed" << std::endl;
}

/* getter */
std::string ClapTrap::getName() const {
    return this->_name;
}
int ClapTrap::getHitPoint() const {
    return this->_hitPoint;
}
int ClapTrap::getEnergyPoint() const {
    return this->_energyPoint;
}
int ClapTrap::getAttackDamage() const {
    return this->_attackDamage;
}

void ClapTrap::attack(const std::string& target) {
    if (this->_hitPoint <= 0 || this->_energyPoint <= 0) {
        std::cout << this->_name << " can't do anything" << std::endl;
        return ;
    }
    this->_energyPoint--;
    std::cout << "[ATTACK]" << std::endl;
    std::cout << "[ATTACK] " + this->_name + " attacks " + target + "!!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    this->_hitPoint -= amount;
    std::cout << "[DAMAGE] " + this->_name + " got damage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoint <= 0 || this->_energyPoint <= 0) {
        std::cout << this->_name << " can't do anything" << std::endl;
        return ;
    }
    this->_hitPoint += amount;
    this->_energyPoint--;
    std::cout << "[REPAIR] " + this->_name + " is repairing..." << std::endl;
}