#include <iostream>
#include <string>
#include "Pieza.hpp"
#ifndef PEON_H
#define PEON_H

using namespace std;
class Peon : public Pieza
{
public:
    Peon()
    {
    }
    Peon(string x, string y, char representacion) : Pieza(x, y, representacion)
    {
    }

    string Peon::getX()
    {
        return this->x;
    }
    string Peon::getY()
    {
        return this->y;
    }
};
#endif