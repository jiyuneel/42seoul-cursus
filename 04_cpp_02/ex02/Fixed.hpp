#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _num;
    static const int _bit = 8;

public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& fixed);
    Fixed& operator=(const Fixed& fixed);
    ~Fixed();

    bool operator>(const Fixed& fixed) const;
    bool operator<(const Fixed& fixed) const;
    bool operator>=(const Fixed& fixed) const;
    bool operator<=(const Fixed& fixed) const;
    bool operator==(const Fixed& fixed) const;
    bool operator!=(const Fixed& fixed) const;

    Fixed operator+(const Fixed& fixed);
    Fixed operator-(const Fixed& fixed);
    Fixed operator*(const Fixed& fixed);
    Fixed operator/(const Fixed& fixed);

    Fixed& operator++(void);
    const Fixed operator++(int);
    Fixed& operator--(void);
    const Fixed operator--(int);

    static Fixed& min(Fixed& fixed1, Fixed& fixed2);
    static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
    static Fixed& max(Fixed& fixed1, Fixed& fixed2);
    static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);

    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif