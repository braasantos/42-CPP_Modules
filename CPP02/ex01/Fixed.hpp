#pragma once


# include <iostream>
# include <string>
# include <cmath>


class Fixed
{
    private:
        int _fixedPoint;
        static const int _fractBits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& otherClass);
        Fixed& operator=(const Fixed& other);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

};

std::ostream& operator << (std::ostream& out, Fixed const &obj);