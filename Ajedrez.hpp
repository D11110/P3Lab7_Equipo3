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
    void imprimirTableroNegras()
    {
        cout << "   H  G  F  E  D  C  B  A  " << endl;
        for (int i = 7; i >= 0; i--)
        {
            cout << i << " ";
            for (int j = 7; j >= 0; j--)
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
    void jugar()
    {
        int turnos = 0;
        int x, y, fil, col;
        string coor;
        string jugadorBlancas, jugadorNegras;
        string salida = "bai";
        string comando = "";
        cout << "Ingrese su nombre jugador de piezas blancas" << endl;
        cin >> jugadorBlancas;
        cout << "Ingrese su nombre jugador de piezas negras" << endl;
        cin >> jugadorNegras;
        while (true)
        {
            if (turnos % 2 == 0)
            {
                imprimirTablero();
                cout << jugadorBlancas << endl;
                cout << "Ingrese: ";
                cin >> comando;
                if (comando == salida)
                {
                    break;
                }
                else
                {
                    x = comando[3] - 48;
                    y = comando[2] - 65;
                    fil = comando[6] - 48;
                    col = comando[5] - 65;
                    while (x < 0 || x > 7 || y < 0 || y > 7)
                    {
                        cout << "No se puede, fuera de los limites. \nCoordenada de nuevo-> ";
                        cin >> comando;
                        x = comando[3] - 48;
                        y = comando[2] - 65;
                        fil = comando[6] - 48;
                        col = comando[5] - 65;
                    }
                    while (tablero[x][y] == NULL)
                    {
                        cout << "No se puede, no pieza en la posicion ingresada. \nCoordenada de nuevo-> ";
                        cin >> comando;
                        x = comando[3] - 48;
                        y = comando[2] - 65;
                        fil = comando[6] - 48;
                        col = comando[5] - 65;
                    }

                    while (fil < 0 || fil > 7 || col < 0 || col > 7)
                    {
                        cout << "No se puede, fuera de los limites. \nCoordenada de nuevo->  ";
                        cin >> comando;
                        x = comando[3] - 48;
                        y = comando[2] - 65;
                        fil = comando[6] - 48;
                        col = comando[5] - 65;
                    }
                    if (tablero[x][y]->validarMovimiento(fil, col, tablero))
                    {
                        imprimirTablero();
                        turnos++;
                    }
                    else
                    {
                        cout << "\nAlgo salio mal. Intente de nuevo.\n";
                    }
                }
            }
            else
            {
                imprimirTableroNegras();
                cout << jugadorNegras << endl;
                cout << "Ingrese: ";
                cin >> comando;
                if (comando == salida)
                {
                    break;
                }
                else
                {
                    x = comando[3] - 48;
                    y = comando[2] - 65;
                    fil = comando[6] - 48;
                    col = comando[5] - 65;
                    while (x < 0 || x > 7 || y < 0 || y > 7)
                    {
                        cout << "No se puede, fuera de los limites. \nCoordenada de nuevo-> ";
                        cin >> comando;
                        x = comando[3] - 48;
                        y = comando[2] - 65;
                        fil = comando[6] - 48;
                        col = comando[5] - 65;
                    }
                    while (tablero[x][y] == NULL)
                    {
                        cout << "No se puede, no pieza en la posicion ingresada. \nCoordenada de nuevo-> ";
                        cin >> comando;
                        x = comando[3] - 48;
                        y = comando[2] - 65;
                        fil = comando[6] - 48;
                        col = comando[5] - 65;
                    }

                    while (fil < 0 || fil > 7 || col < 0 || col > 7)
                    {
                        cout << "No se puede, fuera de los limites. \nCoordenada de nuevo-> ";
                        cin >> comando;
                        x = comando[3] - 48;
                        y = comando[2] - 65;
                        fil = comando[6] - 48;
                        col = comando[5] - 65;
                    }
                    if (tablero[x][y]->movimiento(fil, col, tablero))
                    {
                        imprimirTableroNegras();
                        turnos++;
                    }
                    else
                    {
                        cout << "\nAlgo inesperado ocurrio. Intente de nuevo.\n";
                    }
                }
            }
        }
    }

    ~Ajedrez();
};
#endif