#include "Rey.hpp"

Rey::Rey()
{
}
Rey::Rey(std::string x, std::string y, char represenacion) : Pieza(x, y, represenacion)
{
}
std::string Rey::getX()
{
    return this->x;
}
std::string Rey::getY()
{
    return this->y;
}
