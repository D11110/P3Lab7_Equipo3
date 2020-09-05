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
            for (int j = 0; j < 8; i++)
            {
                if (i == 1)
                {
                    char posicion = 97;
                    tablero[i][j] = new Peon(posicion, to_string(i+1), 'p');
                    posicion++;
                }
                if (i < 2)
                {
                    if (i == 0)
                    {
                        if (j == 0 || j == 7)
                        {
                            switch (j)
                            {
                            case 0:
                                tablero[i][j] = new Torre('a', to_string(j), 'r');
                                break;
                            case 7:
                                tablero[i][j] = new Torre('h', to_string(j), 'r');
                                break;
                            default:
                                break;
                            }
                        }
                        if (j == 1 || j == 6)
                        {
                            switch (j)
                            {
                            case 1:
                                tablero[i][j] = new Caballo('b', to_string(j), 'n');
                                break;
                            case 6:
                                tablero[i][j] = new Caballo('g', to_string(j), 'n');
                                break;
                            default:
                                break;
                            }
                        }
                        if (j == 2 || j == 5)
                        {
                            switch (j)
                            {
                            case 2:
                                tablero[i][j] = new Alfil('c', to_string(j), 'b');
                                break;
                            case 5:
                                tablero[i][j] = new Alfil('f', to_string(j), 'b');
                                break;
                            default:
                                break;
                            }
                        }
                        if (j == 3)
                        {
                            tablero[i][j] = new Rey('d', to_string(j), 'k');
                        }
                        if (j == 4)
                        {

                            tablero[i][j] = new Reina('e', to_string(j), 'q');
                        }
                    }
                    else if (i == 1)
                    {
                        for (int k = 0; k < 8; k++)
                        {
                            switch (k)
                            {
                            case 0:
                                tablero[i][j] = new Peon('a', to_string(j), 'p');
                                break;
                            case 1:
                                tablero[i][j] = new Peon('b', to_string(j), 'p');
                                break;
                            case 2:
                                tablero[i][j] = new Peon('c', to_string(j), 'p');
                                break;
                            case 3:
                                tablero[i][j] = new Peon('d', to_string(j), 'p');
                                break;
                            case 4:
                                tablero[i][j] = new Peon('e', to_string(j), 'p');
                                break;
                            case 5:
                                tablero[i][j] = new Peon('f', to_string(j), 'p');
                                break;
                            case 6:
                                tablero[i][j] = new Peon('g', to_string(j), 'p');
                                break;
                            case 7:
                                tablero[i][j] = new Peon('h', to_string(j), 'p');
                                break;
                            default:
                                break;
                            }
                        }
                    }
                }
                else if (i >= 6)
                {
                    if (i == 7)
                    {
                        if (j == 0 || j == 7)
                        {
                            switch (j)
                            {
                            case 0:
                                tablero[i][j] = new Torre('a', to_string(j), 'R');
                                break;
                            case 7:
                                tablero[i][j] = new Torre('h', to_string(j), 'R');
                                break;
                            default:
                                break;
                            }
                        }
                        if (j == 1 || j == 6)
                        {
                            switch (j)
                            {
                            case 1:
                                tablero[i][j] = new Caballo('b', to_string(j), 'N');
                                break;
                            case 6:
                                tablero[i][j] = new Caballo('g', to_string(j), 'N');
                                break;
                            default:
                                break;
                            }
                        }
                        if (j == 2 || j == 5)
                        {
                            switch (j)
                            {
                            case 2:
                                tablero[i][j] = new Alfil('c', to_string(j), 'B');
                                break;
                            case 5:
                                tablero[i][j] = new Alfil('f', to_string(j), 'B');
                                break;
                            default:
                                break;
                            }
                        }
                        if (j == 3)
                        {
                            tablero[i][j] = new Rey('d', to_string(j), 'K');
                        }
                        if (j == 4)
                        {

                            tablero[i][j] = new Reina('e', to_string(j), 'Q');
                        }
                    }
                    else if (i == 6)
                    {
                        for (int k = 0; k < 8; k++)
                        {
                            switch (k)
                            {
                            case 0:
                                tablero[i][j] = new Peon('a', to_string(j), 'P');
                                break;
                            case 1:
                                tablero[i][j] = new Peon('b', to_string(j), 'P');
                                break;
                            case 2:
                                tablero[i][j] = new Peon('c', to_string(j), 'P');
                                break;
                            case 3:
                                tablero[i][j] = new Peon('d', to_string(j), 'P');
                                break;
                            case 4:
                                tablero[i][j] = new Peon('e', to_string(j), 'P');
                                break;
                            case 5:
                                tablero[i][j] = new Peon('f', to_string(j), 'P');
                                break;
                            case 6:
                                tablero[i][j] = new Peon('g', to_string(j), 'P');
                                break;
                            case 7:
                                tablero[i][j] = new Peon('h', to_string(j), 'P');
                                break;
                            default:
                                break;
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
    }
    void imprimirTablero()
    {
        cout << "   A  B  C  D  E  F  G  H  " << endl;
        for (int i = 0; i < 8; i++)
        {
            cout << i << " ";
            for (int j = 0; j < 8; j++)
            {
                //cout<<"j "<<j<<endl;
                if (tablero[i][j] == NULL)
                {
                    cout << "[.]";
                }
                else
                {
                    cout << "[" + tablero[i][j]->getRepresentacion() + ']';
                }
            }
            cout << endl;
        }
    }
    void jugar();
    ~Ajedrez();
};
#endif