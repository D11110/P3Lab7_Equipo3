#include <iostream>
#include <string>
#include "Pieza.hpp"

class Rey : public Pieza
{
public:
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

    bool validarMovimiento(std::string, std::string, Pieza ***);
    ~Rey();
};