#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>

class ScavTrap {
private:

public:
    ScavTrap();
    ScavTrap(const std::string name);
    ScavTrap(const ClapTrap& clapTrap);
    ScavTrap& operator=(const ScavTrap& scavTrap);
    ~ScavTrap();
};

#endif