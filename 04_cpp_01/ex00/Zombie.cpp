#include "Zombie.hpp"

Zombie::Zombie() {}
Zombie::~Zombie() {
    std::cout << this->name << " is destroyed." << std::endl;
}

void Zombie::announce() {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}