#ifndef PIEZA_H
#define PIEZA_H
#include <iostream>
#include <string>
using namespace std;
class Pieza
{
protected:
    int fila;
    int columna;
    char representacion;

public:
    Pieza()
    {
    }
    Pieza(int x, int y, char representacion)
    {
        this->fila = x;
        this->columna = y;
        this->representacion = representacion;
    }
    virtual bool validarMovimiento(int, int, Pieza ***){};

    char getRepresentacion()
    {
        return this->representacion;
    };
    bool movimiento(int x, int y, Pieza ***tablero)
    {
        if (validarMovimiento(x, y, tablero))
        {
            if (tablero[x][y] != NULL)
            {
                tablero[x][y] = tablero[fila][columna];
            }

            tablero[x][y] = tablero[fila][columna];
            tablero[fila][columna] = NULL;
            fila = x;
            columna = y;
            return true;
        }
        else
        {
            return false;
        }
    }
};
#endif