#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
protected:
    std::string _name;
    int _hitPoint;
    int _energyPoint;
    int _attackDamage;

public:
    ClapTrap();
    ClapTrap(const std::string name);
    ClapTrap(const ClapTrap& clapTrap);
    ClapTrap& operator=(const ClapTrap& clapTrap);
    virtual ~ClapTrap();

    std::string getName() const;
    int getHitPoint() const;
    int getEnergyPoint() const;
    int getAttackDamage() const;

    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void showStatus();
};

#endif