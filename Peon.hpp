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
    Peon(int posX, int posY, char representacion) : Pieza(fila, columna, representacion)
    {
    }
    bool validarMovimiento(int x, int y, Pieza ***tablero)
    {
        if (tablero[x][y] == NULL)
        {
            if (x < fila || y != columna)
            {
                cout << "Pe";
                return false;
            }
            else
            {
                tablero[x][y] = tablero[fila][columna];
                tablero[fila][columna] = NULL;
                return true;
            }
        }
        else if (tablero[x][y] != NULL)
        {
            if (((y - 1) == columna) || ((y + 1) == columna) && (x == (fila + 1)))
            {
                tablero[x][y] = tablero[fila][columna];
                tablero[fila][columna] = NULL;
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