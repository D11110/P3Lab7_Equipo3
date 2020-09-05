#include <iostream>

#include "Pieza.hpp"
using namespace std;
using namespace std;
#ifndef CABALLO_H
#define CABALLO_H
class Caballo : public Pieza
{
public:
    Caballo() {}

    Caballo(int x, int y, char representacion) : Pieza(x, y, representacion) {}

    bool validarMovimiento(string nuevaPosicion, string posicionActual, Pieza ***tablero)
    {
        int nuevaX, nuevaY, actualX, actualY;
        nuevaX = coordenadaXs(nuevaPosicion);
        nuevaY = coordenadasY(nuevaPosicion);
        actualX = coordenadaXs(posicionActual);
        actualY = coordenadasY(posicionActual);
        if (nuevaX == (actualX - 2) && nuevaY == (actualY - 1))
        {
            return true;
        }
        else if (nuevaX == (actualX - 2) && nuevaY == (actualY + 1))
        {
            return true;
        }
        else if ((nuevaX == actualX && nuevaY == actualY))
        {
            return false;
        }
        else if (nuevaX == (actualX + 2) && nuevaY == (actualY - 1))
        {
            return true;
        }
        else if (nuevaX == actualX + 2 && nuevaY == actualY + 1)
        {
            return true;
        }
        else if (nuevaX == actualX + 1 && nuevaY == actualY + 2)
        {
            return true;
        }
        else if (nuevaX == actualX + 1 && nuevaY == actualY - 2)
        {
            return true;
        }
        else if (nuevaX == actualX - 1 && nuevaY == actualY + 2)
        {
            return true;
        }
        else if (nuevaX == actualX - 1 && nuevaY == actualY - 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    ~Caballo()
    {
    }
};
#endif