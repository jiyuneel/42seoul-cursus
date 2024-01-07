#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void leaks() {
    system("leaks -s animal");
}

int main() {
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    dog->makeSound();
    cat->makeSound();
    animal->makeSound();

    const WrongAnimal* wrongCat = new WrongCat();

    wrongCat->makeSound();

    delete animal;
    delete dog;
    delete cat;

    atexit(leaks);

    return 0;
}