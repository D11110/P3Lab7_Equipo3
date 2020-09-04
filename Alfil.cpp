#include "Alfil.hpp"

Alfil::Alfil()
{
}

Alfil::Alfil(std::string x, std::string y, char representacion) : Pieza(x, y, representacion)
{
}

std::string Alfil::getX()
{
    return this->x;
}
std::string Alfil::getY()
{
    return this->y;
}

Alfil::~Alfil()
{
}