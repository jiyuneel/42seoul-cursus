#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter {
private:
    std::string _name;
    int _numOfMaterias;
    int _numOfTrash;
    AMateria* _inventory[4];
    AMateria*  _floor[100];

public:
    Character();
    Character(const std::string& name);
    Character(const Character& character);
    Character& operator=(const Character& character);
    virtual ~Character();

    virtual const std::string& getName() const;
    int getNumOfMaterias() const;
    AMateria* getMateria(int idx) const;

    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};

#endif