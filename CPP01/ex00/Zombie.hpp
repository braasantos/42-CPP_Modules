#pragma once

# include <iostream>
# include <string>

class Zombie
{
private:
    std::string name;
public:
    Zombie( void );
    Zombie( std::string name ); // constructor w parameters
    ~Zombie( void );
    void announce( void );
};