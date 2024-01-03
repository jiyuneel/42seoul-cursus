#include "Fixed.hpp"

/* Default constructor */
Fixed::Fixed() : _num(0) {
    std::cout << "Default constructor called" << std::endl;
}
/* Copy constructor */
Fixed::Fixed(const Fixed& fixed) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}
/* Copy assignment operator */
Fixed& Fixed::operator=(const Fixed& fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed) {
        this->_num = fixed.getRawBits();
    }
    return (*this);
}
/* Destructor */
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_num;
}

void Fixed::setRawBits( int const raw ) {
    this->_num = raw;
}