#include "Fixed.hpp"


//Fixed-point arithmetic is a way of representing fractional 
//numbers without using floating-point hardware, making it useful 
//in some performance-critical applications


Fixed::Fixed() : _fixedPoint(0)
{
    std::cout << "Default constructor called\n";
}
Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called\n";
    this->_fixedPoint = value << _fractBits;
}
/// @brief          This constructor allows you to create 
//                  a Fixed object from a float value.
//          shifts the value by the fractbits to the left
//          Each left shift by 1 position is equivalent to multiplying the number by 2.
/// @param value    the value to create the object
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called\n";
    this->_fixedPoint = static_cast<int>(roundf(value * (1 << _fractBits)));
}
float Fixed::toFloat() const
{
    return static_cast<float>(this->_fixedPoint) / (1 << _fractBits);
}

int Fixed::toInt() const
{
   return this->_fixedPoint >> _fractBits;
}

Fixed::Fixed(const Fixed& otherClass) : _fixedPoint(otherClass._fixedPoint)
{
    std::cout << "Copy constructor called\n";
}
/// @brief          Allows Fixed objects to be printed using std::cout
/// @param out 
/// @param obj 
/// @return 
std::ostream& operator << (std::ostream& out, const Fixed& obj)
{
    float value = obj.toFloat();
    out << value;
    return out;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        this->_fixedPoint = other._fixedPoint;
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called\n";
    return this->_fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPoint = raw;
}