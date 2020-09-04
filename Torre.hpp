#include <iostream>
#include <string>
#include "Pieza.hpp"

#ifndef TORRE_H
#define TORRE_H

class Torre : public Pieza
{
public:
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
    bool validarMovimiento(std::string, std::string, Pieza ***);
    ~Torre();
};
#endif