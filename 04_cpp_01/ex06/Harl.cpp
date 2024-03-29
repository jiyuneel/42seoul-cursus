#include "Harl.hpp"

void Harl::debug( void ) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
              << "I really do!\n" << std::endl;
}

void Harl::info( void ) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money.\n"
              << "You didn’t put enough bacon in my burger!\n"
              << "If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning( void ) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free.\n"
              << "I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error( void ) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain( std::string level ) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int lev = -1;
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level)
            lev = i;
    }

    switch (lev) {
    case 0:
        this->debug();
        __attribute__((fallthrough));
    case 1:
        this->info();
        __attribute__((fallthrough));
    case 2:
        this->warning();
        __attribute__((fallthrough));
    case 3:
        this->error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}