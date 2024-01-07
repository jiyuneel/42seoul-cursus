#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
protected:
    std::string _type;

public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& animal);
    WrongAnimal& operator=(const WrongAnimal& animal);
    virtual ~WrongAnimal();

    const std::string& getType() const;
    void makeSound() const;
};

#endif