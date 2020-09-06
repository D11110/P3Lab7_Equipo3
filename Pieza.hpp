#ifndef PIEZA_H
#define PIEZA_H
#include <iostream>
#include <string>
#include "Rey.hpp"
using namespace std;
class Pieza
{
protected:
    int x;
    int y;
    char representacion;
    Pieza ***tablero;

public:
    char getRepresentacion()
    {
        return this->representacion;
    }
    int getX()
    {
        return this->x;
    }
    int getY()
    {
        return this->y;
    }
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
    virtual bool validarMovimiento(int, int, int, int) = 0;

    bool movimiento(int _x, int _y, int xViejo, int yViejo)
    {

        int contadordePiezasVacias = 0;
        if (validarMovimiento(_x, _y, xViejo, yViejo))
        {
            if (tablero[_x][_y] != NULL)
            {
                if (Rey *r = dynamic_cast<Rey *>(tablero[xViejo][yViejo]))
                {
                    if (Torre *t = dynamic_cast<Torre *>(tablero[_x][_y]))
                    {
                        for (int i = 0; i < 8; i++)
                        {
                            for (int j = 0; j < 8; j++)
                            {
                                if (tablero[7][i] == NULL)
                                {
                                    contadordePiezasVacias++;
                                }
                            }
                        }
                        if (contadordePiezasVacias == 0)
                        {
                            cout << "No se puede realizar un enroque" << endl;
                            return false;
                        }
                        else
                        {
                            int distanciaEntrePiezas = abs(_x - xViejo);
                            if (distanciaEntrePiezas == 3)
                            {
                                tablero[_x][_y] = tablero[xViejo][yViejo];
                                tablero[xViejo][yViejo] = tablero[_x][_y];
                                return true;
                            }
                            else if (distanciaEntrePiezas == 4)
                            {
                                tablero[_x][_y] = tablero[xViejo][yViejo];
                                tablero[xViejo - 1][yViejo] = tablero[_x][_y];
                                return true;
                            }
                        }
                    }
                }
                else
                {
                    tablero[_x][_y] = tablero[xViejo][yViejo];
                    return true;
                }
            }
            else
            {
                tablero[_x][_y] = tablero[xViejo][yViejo];
                tablero[xViejo][yViejo] = NULL;
                xViejo = _x;
                yViejo = _y;
                return true;
            }
        }
        else
        {
            return false;
        }
    }
};
#endif