#include "Cat.hpp"

Cat::Cat() : type("Cat")
{
    std::cout << "Wait you adopted a " << this->type << " 🐱"<< std::endl;
}
Cat::Cat(std::string name) :type(name)
{

}
Cat::~Cat()
{
    std::cout << this->type << " ran away 🐾" << std::endl;
}
Cat::Cat(const Cat& otherClass) : Animal(otherClass)
{
    this->type = otherClass.type;
    std::cout << "Copy Constructor was called" << std::endl;
}

Cat& Cat::operator=(const Cat& otherClass)
{
    std::cout << "Copy Assignment copy operator was called" << std::endl;
    if (this != &otherClass)
        return *this;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << this->type << " is meowing ♪♪*(´0`)*♪♪" << std::endl;
}
std::string Cat::getType() const
{
    return this->type;
}