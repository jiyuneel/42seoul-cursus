#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
private:
    std::string _name;
    int _hitPoint;
    int _energyPoint;
    int _attackDamage;

public:
    ClapTrap();
    ClapTrap(const std::string name);
    ClapTrap(const ClapTrap& clapTrap);
    ClapTrap& operator=(const ClapTrap& clapTrap);
    ~ClapTrap();

    std::string getName() const;
    int getHitPoint() const;
    int getEnergyPoint() const;
    int getAttackDamage() const;

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif