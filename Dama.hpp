#include <iostream>
#include <string>
#include "Pieza.hpp"
using namespace std;
#ifndef REINA_H
#define REINA_H

class Reina : public Pieza
{
public:
    Reina()
    {
    }
    Reina(string x, string y, char representacion) : Pieza(x, y, representacion)
    {
    }
    string Reina::getX()
    {
        return this->x;
    }
    string Reina::getY()
    {
        return this->y;
    }
};

#endif