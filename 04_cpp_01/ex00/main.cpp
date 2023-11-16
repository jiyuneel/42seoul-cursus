#include "Zombie.hpp"

int main() {
    Zombie zombieA = Zombie("zombieA");
    zombieA.announce();

    Zombie* zombieB = newZombie("zombieB");
    zombieB->announce();
    delete zombieB;

    randomChump("zombieC");
}