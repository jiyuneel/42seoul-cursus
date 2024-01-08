#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria {
public:
    Ice();
    Ice(const Ice& ice);
    Ice& operator=(const Ice& ice);
    virtual ~Ice();

    virtual Ice* clone() const;
    virtual void use(ICharacter& target);
};

#endif