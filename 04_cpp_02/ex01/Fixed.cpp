#include "Fixed.hpp"

/* Constructor */
Fixed::Fixed() : _num(0) {
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->_num = value << this->_bit;
}
Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->_num = roundf(value * (1 << this->_bit));
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

int Fixed::getRawBits( void ) const{
    return this->_num;
}
void Fixed::setRawBits( int const raw ) {
    this->_num = raw;
}

float Fixed::toFloat( void ) const {
    return (float)this->_num / (1 << this->_bit);
}
int Fixed::toInt( void ) const {
    return this->_num >> this->_bit;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    return out << fixed.toFloat();
}