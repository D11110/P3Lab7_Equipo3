#include <iostream>
#include <string>
#include "Pieza.hpp"

#ifndef ALFIL_H
#define ALFIL_H

using namespace std;
class Alfil : public Pieza
{
public:
    Alfil()
    {
    }

    Alfil(int x, int y, char representacion, Pieza ***tablero) : Pieza(x, y, representacion, tablero)
    {
    }

    bool validarMovimiento(int nueva_x, int nueva_y, int vieja_x, int vieja_y)
    {
        int difEnX = nueva_x - vieja_x;
        int difEnY = nueva_y - vieja_y;
        if (abs(difEnX) == abs(difEnY))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    ~Alfil()
    {
    }
};

#endif