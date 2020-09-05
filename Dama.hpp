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
    Reina(int x, int y, char representacion, Pieza ***tablero) : Pieza(x, y, representacion, tablero)
    {
    }

    bool validarMovimiento(int nueva_x, int nueva_y)
    {
        int difEnX = nueva_x - this->x;
        int difEnY = nueva_y - this->y;
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