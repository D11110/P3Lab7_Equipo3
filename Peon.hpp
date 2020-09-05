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
    bool validarMovimiento(int nueva_x, int nueva_y, int vieja_x, int vieja_y)
    {
        //E6---4 6
        int difEnX = nueva_x - vieja_x;
        if (tablero[nueva_x][nueva_y] == NULL)
        {
            if (nueva_y != vieja_y || abs(difEnX) != 1)
            {
                cout << "Pe";
                return false;
            }
            else
            {
                return true;
            }
        }
        else if (tablero[vieja_x][vieja_y] != NULL)
        {
            if (((nueva_y - 1) == vieja_y) || ((nueva_y + 1) == vieja_x))
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
