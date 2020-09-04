#include <iostream>
#include <string>
#include "Pieza.hpp"

#ifndef TORRE_H
#define TORRE_H

using namespace std;

class Torre : public Pieza
{
public:
    Torre()
    {
    }
    Torre(string x, string y, char representacion) : Pieza(x, y, representacion)
    {
    }

    string Torre::getX()
    {
        return this->x;
    }
    string Torre::getY()
    {
        return this->y;
    }

    ~Torre()
    {
    }
    bool validarMovimiento(std::string, std::string, Pieza ***);
    ~Torre();
};
#endif