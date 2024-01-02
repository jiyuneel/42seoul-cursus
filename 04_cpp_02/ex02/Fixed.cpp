#include "Fixed.hpp"

/* Constructor */
Fixed::Fixed() : _num(0) {
    // std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int value) {
    // std::cout << "Int constructor called" << std::endl;
    this->_num = value << this->_bit;
}
Fixed::Fixed(const float value) {
    // std::cout << "Float constructor called" << std::endl;
    this->_num = roundf(value * (1 << this->_bit));
}

/* Copy constructor */
Fixed::Fixed(const Fixed& fixed) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

/* Copy assignment operator */
Fixed& Fixed::operator=(const Fixed& fixed) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed) {
        this->_num = fixed.getRawBits();
    }
    return (*this);
}
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    return out << fixed.toFloat();
}

/* Destructor */
Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

/* 6 comparison operators (>, <, >=, <=, ==, !=) */
bool Fixed::operator>(const Fixed& fixed) const {
    return this->_num > fixed.getRawBits();
}
bool Fixed::operator<(const Fixed& fixed) const {
    return this->_num < fixed.getRawBits();
}
bool Fixed::operator>=(const Fixed& fixed) const {
    return this->_num >= fixed.getRawBits();
}
bool Fixed::operator<=(const Fixed& fixed) const {
    return this->_num <= fixed.getRawBits();
}
bool Fixed::operator==(const Fixed& fixed) const {
    return this->_num == fixed.getRawBits();
}
bool Fixed::operator!=(const Fixed& fixed) const {
    return this->_num != fixed.getRawBits();
}

/* 4 arithmetic operators (+, -, *, /) */
Fixed Fixed::operator+(const Fixed& fixed) {
    return Fixed(this->toFloat() + fixed.toFloat());
}
Fixed Fixed::operator-(const Fixed& fixed) {
    return Fixed(this->toFloat() - fixed.toFloat());
}
Fixed Fixed::operator*(const Fixed& fixed) {
    return Fixed(this->toFloat() * fixed.toFloat());
}
Fixed Fixed::operator/(const Fixed& fixed) {
    return Fixed(this->toFloat() / fixed.toFloat());
}

/* 4 increment/decrement operators (++x, x++, --x, x--) */
Fixed& Fixed::operator++(void) {
    this->_num++;
    return *this;
}
const Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    this->_num++;
    return tmp;
}
Fixed& Fixed::operator--(void) {
    this->_num--;
    return *this;
}
const Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    this->_num--;
    return tmp;
}

/* min/max functions */
Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2) {
    if (fixed1 < fixed2)
        return fixed1;
    return fixed2;
}
const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2) {
    if (fixed1 < fixed2)
        return fixed1;
    return fixed2;
}
Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2) {
    if (fixed1 > fixed2)
        return fixed1;
    return fixed2;
}
const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2) {
    if (fixed1 > fixed2)
        return fixed1;
    return fixed2;
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