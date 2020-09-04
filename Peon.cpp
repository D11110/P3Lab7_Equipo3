#include "Peon.hpp"

Peon::Peon()
{
}
Peon::Peon(std::string x, std::string y, char representacion) : Pieza(x, y, representacion)
{
}

std::string Peon::getX()
{
    return this->x;
}
std::string Peon::getY()
{
    return this->y;
}
