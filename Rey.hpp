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
    Rey(int x, int y, char represenacion) : Pieza(fila, columna, represenacion)
    {
    }

    bool validarMovimiento(int x, int y, Pieza ***tablero)
    {
        int difEnX = x - fila;
        int difEnY = y - columna;
        if ((abs(difEnY) == 1 && difEnX == 0) || (abs(difEnX) == 1 && difEnY == 0))
        {
            return true;
        }
        else if ((abs(difEnY) == 1) && (abs(difEnX) == 1))
        {
            return true;
        }
        else
        {
            cout << "aber";
            return false;
        }
    }
    ~Rey();
};

#endif