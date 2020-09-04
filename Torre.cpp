#include "Torre.hpp"
Torre::Torre()
{
}
Torre::Torre(std::string x, std::string y, char representacion) : Pieza(x, y, representacion)
{
}

std::string Torre::getX()
{
    return this->x;
}
std::string Torre::getY()
{
    return this->y;
}

Torre::~Torre()
{
}