#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
    std::string name;

public:
    Zombie();
    ~Zombie();

    // std::string getName();
    // void setName(std::string name);

    void announce();
};

#endif