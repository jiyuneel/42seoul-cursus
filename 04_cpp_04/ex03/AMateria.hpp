#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
class ICharacter;

class AMateria {
protected:
    std::string _type;

public:
    AMateria();
    AMateria(const std::string& type);
    AMateria(const AMateria& aMateria);
    AMateria& operator=(const AMateria& aMateria);
    virtual ~AMateria();

    const std::string& getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif