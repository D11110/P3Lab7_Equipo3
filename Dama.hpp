#include <iostream>
#include <string>
#include "Pieza.hpp"

class Reina : public Pieza
{
public:
    Reina::Reina()
    {
    }
    Reina::Reina(std::string x, std::string y, char representacion) : Pieza(x, y, representacion)
    {
    }
    std::string Reina::getX()
    {
        return this->x;
    }
    std::string Reina::getY()
    {
        return this->y;
    }
};