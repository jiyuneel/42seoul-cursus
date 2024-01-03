#include "Fixed.hpp"

/* Constructor */
Fixed::Fixed() : _num(0) {}
Fixed::Fixed(const int value) {
    this->_num = value << this->_bit;
}
Fixed::Fixed(const float value) {
    this->_num = roundf(value * (1 << this->_bit));
}

/* Copy constructor */
Fixed::Fixed(const Fixed& fixed) {
    *this = fixed;
}

/* Copy assignment operator */
Fixed& Fixed::operator=(const Fixed& fixed) {
    if (this != &fixed) {
        this->_num = fixed.getRawBits();
    }
    return (*this);
}

/* Destructor */
Fixed::~Fixed() {}

/* insertion operator (<<) */
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    return out << fixed.toFloat();
}

/* comparison operators (>, <, >=, <=, ==, !=) */
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

/* arithmetic operators (+, -, *, /) */
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

/* increment/decrement operators (++x, x++, --x, x--) */
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