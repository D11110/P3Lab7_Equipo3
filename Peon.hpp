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
    bool validarMovimiento(int nueva_y, int nueva_x)
    {
        if (this->tablero[nueva_x][nueva_y] == NULL)
        {
            if (nueva_x < x || nueva_y != y)
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
            if (((nueva_y - 1) == this->y) || ((nueva_y + 1) == this->x) && (nueva_x == (this->x + 1)))
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

