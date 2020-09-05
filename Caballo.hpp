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

    Caballo(int x, int y, char representacion) : Pieza(fila, columna, representacion) {}

    bool validarMovimiento(int x, int y, Pieza ***tablero)
    {
        if (tablero[x][y] == NULL)
        {

            if (x == fila - 2 && y == columna - 1)
            {
                return true;
            }
            else if (x == fila - 1 && y == columna - 2)
            {
                return true;
            }
            else if (x == fila - 2 && y == columna + 1)
            {
                return true;
            }
            else if (x == fila - 2 && y == columna + 1)
            {
                return true;
            }
            else if (x == fila + 1 && y == columna - 2)
            {
                return true;
            }
            else if (x == fila + 2 && y == columna - 1)
            {
                return true;
            }
            else if (x == fila + 1 && y == columna + 2)
            {
                return true;
            }
            else if (x == fila + 2 && y == columna + 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    ~Caballo()
    {
    }
};
#endif