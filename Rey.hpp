#include <iostream>
#include <string>
#include "Pieza.hpp"
#ifndef REY_H
#define REY_H

using namespace std;
class Rey : public Pieza
{
public:
    Rey()
    {
    }
    Rey(string x, string y, char represenacion) : Pieza(x, y, represenacion)
    {
    }
    string Rey::getX()
    {
        return this->x;
    }
    string Rey::getY()
    {
        return this->y;
    }

    bool validarMovimiento(std::string, std::string, Pieza ***);
    ~Rey();
};
#endif