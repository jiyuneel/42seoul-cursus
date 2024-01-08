#include "Dog.hpp"
#include "Cat.hpp"

void leaks() {
    system("leaks -s brain");
}

int main() {
    atexit(leaks);
    const Animal* animals[4];

    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0; i < 4; i++) {
        delete animals[i];
    }

    const Dog* dog1 = new Dog();
    dog1->getBrain()->setIdea("🐾🐾🐾🐾", 0);
    dog1->getBrain()->setIdea("🦴🦴🦴🦴", 1);

    const Dog* dog2 = new Dog(*dog1);
    dog2->getBrain()->setIdea("🐶🐶🐶🐶", 0);

    std::cout << dog1->getBrain()->getIdea(0) << std::endl;
    std::cout << dog1->getBrain()->getIdea(1) << std::endl;
    std::cout << dog2->getBrain()->getIdea(0) << std::endl;
    std::cout << dog2->getBrain()->getIdea(1) << std::endl;

    delete dog1;
    delete dog2;

    return 0;
}