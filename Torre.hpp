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
    Torre(int x, int y, char representacion) : Pieza(fila, columna, representacion)
    {
    }

    bool validarMovimiento(int x, int y, Pieza ***tablero)
    {
        int difEnX = x - fila;
        int difEnY = y - columna;
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