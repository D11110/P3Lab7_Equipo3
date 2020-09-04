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

    Alfil(std::string x, std::string y, char representacion) : Pieza(x, y, representacion)
    {
    }

    string Alfil::getX()
    {
        return this->x;
    }
    string Alfil::getY()
    {
        return this->y;
    }

    ~Alfil()
    {
    }
    bool Alfil::validarMovimiento(std::string nuevaPosicion, std::string posicionActual, Pieza ***tablero)
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
            return true;
        }
        else
        {
            return false;
        }
    }

    int coordenadaXs(std::string posicionAConvertir)
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
    int coordenadasY(std::string posicionAconvertir)
    {
        std::string aux = "";
        aux += posicionAconvertir.at(1);
        int y = stoi(aux);
        return y;
    }
};
#endif