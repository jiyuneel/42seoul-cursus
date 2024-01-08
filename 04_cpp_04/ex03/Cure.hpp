#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria {
public:
    Cure();
    Cure(const Cure& cure);
    Cure& operator=(const Cure& cure);
    virtual ~Cure();

    virtual Cure* clone() const;
    virtual void use(ICharacter& target);
};

#endif