#include "Pieza.hpp"

Pieza::Pieza()
{
}
Pieza::Pieza(std::string x, std::string y, char representacion)
{
    this->x = x;
    this->y = y;
    this->representacion = representacion;
}
