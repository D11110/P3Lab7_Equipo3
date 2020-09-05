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
    Peon(int posX, int posY, char representacion, Pieza ***tablero) : Pieza(x, y, representacion, tablero)
    {
    }
    bool validarMovimiento(int nueva_x, int nueva_y)
    {
        //E6---4 6
        int difEnX = nueva_x - this->x;
        if (this->tablero[nueva_x][nueva_y] == NULL)
        {
            if (nueva_y != y || abs(difEnX) != 1)
            {
                cout << "Pe";
                return false;
            }
            else
            {
                return true;
            }
        }
        else if (tablero[x][y] != NULL)
        {
            if (((nueva_y - 1) == this->y) || ((nueva_y + 1) == this->x))
            {
                return true;
            }
            else
            {
                cout << "rro;";
                return false;
            }
        }
    }
};

#endif
