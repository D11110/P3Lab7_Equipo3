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
    int coordenadasEnX(char x)
    {
        int resp;
        switch (x)
        {
        case 'A':
            resp = 0;
            break;
        case 'B':
            resp = 1;
            break;
        case 'C':
            resp = 2;
            break;
        case 'D':
            resp = 3;
            break;
        case 'E':
            resp = 4;
            break;
        case 'F':
            resp = 4;
            break;
        case 'G':
            resp = 5;
            break;
        case 'H':
            resp = 7;
            break;
        default:
            break;
        }
        return resp;
    }
    int coordenadasEnY(char y)
    {
        int i=;
        for (int i = 0; i < ; i++)
        {
            /* code */
        }
        
    }
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

                            tablero[i][j] = new Torre(i, j, 'r', tablero);
                        }
                        if (j == 1 || j == 6)
                        {

                            tablero[i][j] = new Caballo(i, j, 'n', tablero);
                        }
                        if (j == 2 || j == 5)
                        {

                            tablero[i][j] = new Alfil(i, j, 'b', tablero);
                        }
                        if (j == 3)
                        {

                            tablero[i][j] = new Rey(i, j, 'k', tablero);
                        }
                        if (j == 4)
                        {

                            tablero[i][j] = new Reina(i, j, 'q', tablero);
                        }
                    }
                    else if (i == 1)
                    {
                        tablero[i][j] = new Peon(i, j, 'p', tablero);
                    }
                }
                else if (i >= 6)
                {
                    if (i == 6)
                    {
                        tablero[i][j] = new Peon(i, j, 'P', tablero);
                    }
                    else if (i == 7)
                    {
                        if (j == 0 || j == 7)
                        {
                            tablero[i][j] = new Torre(i, j, 'R', tablero);
                        }
                        else if (j == 1 || j == 6)
                        {
                            tablero[i][j] = new Caballo(i, j, 'N', tablero);
                        }
                        else if (j == 2 || j == 5)
                        {
                            tablero[i][j] = new Alfil(i, j, 'B', tablero);
                        }
                        else if (j == 3)
                        {
                            tablero[i][j] = new Reina(i, j, 'Q', tablero);
                        }
                        else if (j == 4)
                        {
                            tablero[i][j] = new Rey(i, j, 'K', tablero);
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
        int xDestino, yDestino, xActual, yActual;
        string jugadorBlancas, jugadorNegras;
        string salida = "bai";
        cout << "Ingrese su nombre jugador de piezas blancas" << endl;
        cin >> jugadorBlancas;
        cout << "Ingrese su nombre jugador de piezas negras" << endl;
        cin >> jugadorNegras;
        string comando;
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
                    //P|E6-E5
                    cout << comando << endl;
                    xActual = coordenadasEnX(comando.at(2));
                    yActual = coordenadasEnY(comando.at(3));
                    xDestino = coordenadasEnX(comando.at(5));
                    yDestino = coordenadasEnY(comando.at(6));
                    cout << "Posicion actual" << xActual << " " << yActual;
                    cout << "Posicion NUeva" << xDestino << " " << yDestino;
                    // while (xDestino < 0 || xDestino > 7 || yDestino < 0 || yDestino > 7)
                    // {
                    //     cout << "No se puede, fuera de los limites. \nCoordenada de nuevo-> ";
                    //     cin >> comando;
                    //     xActual = comando.at(2) - 65;
                    //     yActual = comando.at(3) - 48;
                    //     xDestino = comando.at(5) - 65;
                    //     yDestino = comando.at(6) - 48;
                    // }
                    // while (tablero[xActual][yActual] == NULL)
                    // {
                    //     cout << "No se puede, no pieza en la posicion ingresada. \nCoordenada de nuevo-> ";
                    //     cin >> comando;
                    //     xActual = comando.at(2) - 65;
                    //     yActual = comando.at(3) - 48;
                    //     xDestino = comando.at(5) - 65;
                    //     yDestino = comando.at(6) - 48;
                    // }

                    // while (xActual < 0 || xActual > 7 || yActual < 0 || yActual > 7)
                    // {
                    //     cout << "No se puede, fuera de los limites. \nCoordenada de nuevo->  ";
                    //     cin >> comando;
                    //     xActual = comando.at(2) - 65;
                    //     yActual = comando.at(3) - 48;
                    //     xDestino = comando.at(5) - 65;
                    //     yDestino = comando.at(6) - 48;
                    // }
                    if (tablero[xActual][yActual]->validarMovimiento(xDestino, yDestino))
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
                    xActual = comando.at(2) - 65;
                    yActual = comando.at(3) - 48;
                    xDestino = comando.at(5) - 65;
                    yDestino = comando.at(6) - 48;
                    while (xDestino < 0 || xDestino > 7 || yDestino < 0 || yDestino > 7)
                    {
                        cout << "No se puede, fuera de los limites. \nCoordenada de nuevo-> ";
                        cin >> comando;
                        xActual = comando.at(2) - 65;
                        yActual = comando.at(3) - 48;
                        xDestino = comando.at(5) - 65;
                        yDestino = comando.at(6) - 48;
                    }
                    while (tablero[xActual][yActual] == NULL)
                    {
                        cout << "No se puede, no pieza en la posicion ingresada. \nCoordenada de nuevo-> ";
                        cin >> comando;
                        xActual = comando.at(2) - 65;
                        yActual = comando.at(3) - 48;
                        xDestino = comando.at(5) - 65;
                        yDestino = comando.at(6) - 48;
                    }

                    while (xActual < 0 || xActual > 7 || yActual < 0 || yActual > 7)
                    {
                        cout << "No se puede, fuera de los limites. \nCoordenada de nuevo-> ";
                        cin >> comando;
                        xActual = comando.at(2) - 65;
                        yActual = comando.at(3) - 48;
                        xDestino = comando.at(5) - 65;
                        yDestino = comando.at(6) - 48;
                    }
                    if (tablero[xActual][yActual]->validarMovimiento(xDestino, yDestino))
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

    ~Ajedrez(){};
};
#endif
