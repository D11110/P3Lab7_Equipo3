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

    Alfil(char x, string y, char representacion) : Pieza(x, y, representacion)
    {
    }

    char getX()
    {
        return this->x;
    }
    string getY()
    {
        return this->y;
    }
    char getRepresentacion()
    {
        return this->representacion;
    }
    ~Alfil()
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
        else
        {
            return false;
        }
    }
};

#endif