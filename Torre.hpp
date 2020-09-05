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
    Torre(int x, int y, char representacion, Pieza ***tablero) : Pieza(x, y, representacion, tablero)
    {
    }

    bool validarMovimiento(int nueva_x, int nueva_y)
    {
        int difEnX = nueva_x - this->x;
        int difEnY = nueva_y - this->y;
        if (difEnY == 0 || difEnX == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    ~Torre()
    {
    }
};

#endif