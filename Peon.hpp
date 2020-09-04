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
    Peon(string x, string y, char representacion) : Pieza(x, y, representacion)
    {
    }
    bool validarMovimiento(string nuevaPosicion, string posicionActual, Pieza ***tablero)
    {
        int nuevaX, nuevaY, actualX, actualY;
        nuevaX = coordenadaXs(nuevaPosicion);
        nuevaY = coordenadasY(nuevaPosicion);
        actualX = coordenadaXs(posicionActual);
        actualY = coordenadasY(posicionActual);
        int difEnX = nuevaX - actualX;
        int difEnY = nuevaY - actualY;

        if (tablero[nuevaX][nuevaY] == NULL)
        {
            if ((nuevaY != actualY) || (nuevaX < actualX))
            {
                return false;
            }
            else
            {
                tablero[nuevaX][nuevaY] = tablero[actualX][actualY];
                tablero[actualX][actualY] = NULL;
                return true;
            }
        }
        else if (tablero[nuevaX][nuevaY] != NULL)
        {
            if (((nuevaY - 1) == actualY) || ((nuevaY + 1) == actualY) && (nuevaX == (actualX + 1)))
            {
                tablero[nuevaX][nuevaY] = tablero[actualX][actualY];
                tablero[actualX][actualY] = NULL;
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    string getX()
    {
        return this->x;
    }
    string getY()
    {
        return this->y;
    }
};

#endif