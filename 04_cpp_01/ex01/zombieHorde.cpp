#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde( int N, std::string name ) {
    Zombie* zombies = new Zombie[N];

    std::stringstream ss;
    for (int i = 0; i < N; i++) {
        ss.str(std::string());
        ss << i + 1;
        zombies[i].setName(name + ss.str());
    }

    return zombies;
}