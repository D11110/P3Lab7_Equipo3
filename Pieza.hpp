#ifndef PIEZA_H
#define PIEZA_H
#include <iostream>
#include <string>
using namespace std;
class Pieza
{
protected:
    int x;
    int y;
    char representacion;
    Pieza ***tablero;

public:
    Pieza()
    {
    }
    Pieza(int x, int y, char representacion, Pieza ***tablero)
    {
        this->x = x;
        this->y = y;
        this->representacion = representacion;
        this->tablero = tablero;
    }
    virtual bool validarMovimiento(int, int) = 0;

    char getRepresentacion()
    {
        return this->representacion;
    };
    bool movimiento(int _x, int _y)
    {
        if (validarMovimiento(_x, _y))
        {
            if (tablero[_x][_y] != NULL)
            {
                tablero[_x][_y] = tablero[this->x][this->y];
            }

            tablero[_x][_y] = tablero[this->x][this->y];
            tablero[this->x][this->y] = NULL;
            this->x = _x;
            this->y = _y;
            return true;
        }
        else
        {
            return false;
        }
    }
};
#endif