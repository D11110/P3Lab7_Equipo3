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

    Alfil(int x, int y, char representacion) : Pieza(fila, columna, representacion)
    {
    }

    bool validarMovimiento(int x, int y, Pieza ***tablero)
    {
        int difEnX = x - fila;
        int difEnY = y - columna;
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