#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
    int _numOfMaterias;
    AMateria* _inventory[4];

public:
    MateriaSource();
    MateriaSource(const MateriaSource& materiaSource);
    MateriaSource& operator=(const MateriaSource& materiaSource);
    virtual ~MateriaSource();

    int getNumOfMaterias() const;
    AMateria* getMateria(int idx) const;

    virtual void learnMateria(AMateria* materia);
    virtual AMateria* createMateria(const std::string& type);
};

#endif