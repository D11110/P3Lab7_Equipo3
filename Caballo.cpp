#include "Caballo.hpp"

Caballo::Caballo() {}

Caballo::Caballo(std::string x, std::string y, char representacion) : Pieza(x, y, representacion) {}

std::string Caballo::getX()
{
    return this->x;
}
std::string Caballo::getY()
{
    return this->y;
}


Caballo::~Caballo()
{
}