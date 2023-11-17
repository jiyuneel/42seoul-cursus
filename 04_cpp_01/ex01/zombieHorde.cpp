#include "Zombie.hpp"
#include <string>

Zombie* zombieHorde( int N, std::string name ) {
    Zombie* zombies = new Zombie[N];

    for (int i = 0; i < N; i++)
        zombies->setName(name + std::to_string(i + 1));

    return zombies;
}