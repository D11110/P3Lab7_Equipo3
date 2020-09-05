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
    Reina(int x, int y, char representacion) : Pieza(x, y, representacion)
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
        if (abs(difEnX) == abs(difEnY))
        {
            tablero[nuevaX][nuevaY] = tablero[actualX][actualY];
            tablero[actualX][actualY] = NULL;
            return true;
        }
        else if (difEnY == 0 || difEnX == 0)
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
};
#endif