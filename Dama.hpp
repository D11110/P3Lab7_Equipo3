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
    Reina(int x, int y, char representacion) : Pieza(fila, columna, representacion)
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
        else if (difEnY == 0 || difEnX == 0)
        {
            return true;
        }
        else
        {
            cout << "sal";
            return false;
        }
    }
    ~Reina(){};
};
#endif