#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain is creating new ideas" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = "Idea";
}
Brain::~Brain()
{
    std::cout << "Brain is tired" << std::endl;
}
Brain::Brain(const Brain &other)
{
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}
Brain& Brain::operator=(const Brain &otherClass)
{
    if (this != &otherClass)
        return *this;
    return *this;
}

void Brain::newIdea(int index, std::string idea)
{
    ideas[index] = idea;
}
