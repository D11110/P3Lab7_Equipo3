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
    Torre(int x, int y, char representacion) : Pieza(x, y, representacion)
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