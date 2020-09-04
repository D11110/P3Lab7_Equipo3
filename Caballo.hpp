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

    Caballo(string x, string y, char representacion) : Pieza(x, y, representacion) {}

    string getX()
    {
        return this->x;
    }
    string getY()
    {
        return this->y;
    }
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
int coordenadaXs(string posicionAConvertir)
{
    int x = 0;
    switch (posicionAConvertir.at(0))
    {
    case 'a':
        x = 1;
        break;
    case 'b':
        x = 2;
        break;
    case 'c':
        x = 3;
        break;
    case 'd':
        x = 4;
        break;
    case 'e':
        x = 5;
        break;
    case 'f':
        x = 6;
        break;
    case 'g':
        x = 7;
        break;
    case 'h':
        x = 8;
        break;
    default:
        break;
    }
    return x;
}
int coordenadasY(string posicionAconvertir)
{
    std::string aux = "";
    aux += posicionAconvertir.at(1);
    int y = stoi(aux);
    return y;
}
#endif