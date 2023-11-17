#include "Zombie.hpp"

Zombie::Zombie() {}
Zombie::~Zombie() {
    std::cout << this->_name << " is dead." << std::endl;
}

void Zombie::setName( std::string name ) {
    this->_name = name;
}

void Zombie::announce() {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}