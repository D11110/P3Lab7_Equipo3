#include <iostream>
#include "Pieza.hpp"
#include "Alfil.hpp"
#include "Caballo.hpp"
#include "Dama.hpp"
#include "Peon.hpp"
#include "Rey.hpp"
#include "Torre.hpp"

#ifndef AJEDREZ_H
#define AJEDREZ_H

class Ajedrez
{
private:
    Pieza ***tablero;

public:
    Ajedrez()
    {
    }
    void crearTablero()
    {
        tablero = new Pieza **[8];
        for (int i = 0; i < 8; i++)
        {
            tablero[i] = new Pieza *[8];
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (i < 2)
                {
                    if (i == 0)
                    {
                        if (j == 0 || j == 7)
                        {

                            tablero[i][j] = new Torre(i, j, 'r');
                        }
                        if (j == 1 || j == 6)
                        {

                            tablero[i][j] = new Caballo(i, j, 'n');
                        }
                        if (j == 2 || j == 5)
                        {

                            tablero[i][j] = new Alfil(i, j, 'b');
                        }
                        if (j == 3)
                        {

                            tablero[i][j] = new Rey(i, j, 'k');
                        }
                        if (j == 4)
                        {

                            tablero[i][j] = new Reina(i, j, 'q');
                        }
                    }
                    else if (i == 1)
                    {
                        tablero[i][j] = new Peon(i, j, 'p');
                    }
                }
                else if (i >= 6)
                {
                    if (i == 6)
                    {
                        tablero[i][j] = new Peon(i, j, 'P');
                    }
                    else if (i == 7)
                    {
                        if (j == 0 || j == 7)
                        {
                            tablero[i][j] = new Torre(i, j, 'R');
                        }
                        else if (j == 1 || j == 6)
                        {
                            tablero[i][j] = new Caballo(i, j, 'N');
                        }
                        else if (j == 2 || j == 5)
                        {
                            tablero[i][j] = new Alfil(i, j, 'B');
                        }
                        else if (j == 3)
                        {
                            tablero[i][j] = new Reina(i, j, 'Q');
                        }
                        else if (j == 4)
                        {
                            tablero[i][j] = new Rey(i, j, 'K');
                        }
                    }
                }
                else
                {
                    tablero[i][j] = NULL;
                }
            }
        }
    }
    void imprimirTablero()
    {
        cout << "   A  B  C  D  E  F  G  H  " << endl;
        for (int i = 0; i < 8; i++)
        {
            cout << i << " ";
            for (int j = 0; j < 8; j++)
            {
                if (tablero[i][j] == NULL)
                {
                    cout << "[ ]";
                }
                else
                {
                    cout << "[";
                    cout << tablero[i][j]->getRepresentacion();
                    cout << "]";
                }
            }
            cout << endl;
        }
    }
    void jugar();
    ~Ajedrez();
};
#endif