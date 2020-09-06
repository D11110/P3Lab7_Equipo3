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
    bool enrocar(int xRey, int yRey, int xTorre, int yTorre, Pieza ***tablero)
    {
        int contadordePiezasVacias = 0;
        if (Rey *r = dynamic_cast<Rey *>(tablero[xRey][yRey]))
        {
            if (Torre *t = dynamic_cast<Torre *>(tablero[xTorre][yTorre]))
            {
                for (int i = 0; i < 8; i++)
                {
                    if (tablero[7][i] == NULL)
                    {
                        contadordePiezasVacias++;
                    }
                }
                if (contadordePiezasVacias == 0)
                {
                    cout << "No se puede realizar un enroque" << endl;
                    return false;
                }
                else
                {
                    int distanciaEntrePiezas = abs(yRey - yTorre);
                    if (distanciaEntrePiezas == 3)
                    {
                        Torre *torreAEnrocar = dynamic_cast<Torre *>(tablero[xTorre][yTorre]);
                        Rey *reyAEnrocar = dynamic_cast<Rey *>(tablero[xRey][yRey]);
                        tablero[xTorre][yTorre] = reyAEnrocar;
                        tablero[xRey][yRey] = NULL;
                        tablero[xRey][yRey + 1] = torreAEnrocar;
                        return true;
                    }
                    else if (distanciaEntrePiezas == 4)
                    {
                        Torre *torreAEnrocar = dynamic_cast<Torre *>(tablero[xTorre][yTorre]);
                        Rey *reyAEnrocar = dynamic_cast<Rey *>(tablero[xRey][yRey]);
                        tablero[xTorre][yTorre] = reyAEnrocar;
                        tablero[xRey][yRey] = NULL;
                        tablero[xRey][yRey + 2] = torreAEnrocar;
                        return true;
                    }
                }
            }
        }
    }
    bool coronarPeon(int posXPeon, int posYPeon, int posXActualPeon, int posActualYPeon, char representacionPieza, Pieza ***tablero)
    {
        if (isupper(representacionPieza) != 0 && posXPeon == 0)
        {

            int eleccion = 0;
            cout << "Elija la pieza a coronar su peon\n1. DAMA 2. CABALLO 3. TORRE 4. ALFIL" << endl;
            cin >> eleccion;
            switch (eleccion)
            {
            case 1:
            {
                tablero[posXPeon][posYPeon] = new Reina(posXPeon, posYPeon, 'Q', tablero);
                tablero[posXActualPeon][posActualYPeon] = NULL;
            }
            break;
            case 2:
            {
                tablero[posXPeon][posYPeon] = new Caballo(posXPeon, posYPeon, 'N', tablero);
                tablero[posXActualPeon][posActualYPeon] = NULL;
            }
            break;
            case 3:
            {
                tablero[posXPeon][posYPeon] = new Torre(posXPeon, posYPeon, 'R', tablero);
                tablero[posXActualPeon][posActualYPeon] = NULL;
            }
            break;
            case 4:
            {
                tablero[posXPeon][posYPeon] = new Alfil(posXPeon, posYPeon, 'B', tablero);
                tablero[posXActualPeon][posActualYPeon] = NULL;
            }
            break;
            default:
                break;
            }
            return true;
        }
        else if (isupper(representacionPieza) == 0 && posXPeon == 7)
        {
            int eleccion = 0;
            cout << "Elija la pieza a coronar su peon\n1. DAMA 2. CABALLO 3. TORRE 4. ALFIL" << endl;
            cin >> eleccion;
            switch (eleccion)
            {
            case 1:
            {
                tablero[posXPeon][posYPeon] = new Reina(posXPeon, posYPeon, 'q', tablero);
                tablero[posXActualPeon][posActualYPeon] = NULL;
            }
            break;
            case 2:
            {
                tablero[posXPeon][posYPeon] = new Caballo(posXPeon, posYPeon, 'n', tablero);
                tablero[posXActualPeon][posActualYPeon] = NULL;
            }
            break;
            case 3:
            {
                tablero[posXPeon][posYPeon] = new Torre(posXPeon, posYPeon, 'r', tablero);
                tablero[posXActualPeon][posActualYPeon] = NULL;
            }
            break;
            case 4:
            {
                tablero[posXPeon][posYPeon] = new Alfil(posXPeon, posYPeon, 'b', tablero);
                tablero[posXActualPeon][posActualYPeon] = NULL;
            }
            break;
            default:
                break;
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    bool ahogado(Pieza ***tablero, char tipoDerey, int nuevaXDeRey, int nuevaYdeRey)
    {
        int contadorPiezasQuePuedenAhogar = 0;
        int contadorPIezasEnemigasTotales = 0;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (Rey *r = dynamic_cast<Rey *>(tablero[i][j]))
                {
                    if (isupper(tipoDerey) != 0)
                    {
                        char piezaDelEnemigo = tablero[i][j]->getRepresentacion();
                        if (isupper(piezaDelEnemigo) == 0)
                        {
                            contadorPIezasEnemigasTotales++;
                            if (tablero[nuevaXDeRey][nuevaYdeRey]->validarMovimiento(i, j, nuevaYdeRey, nuevaYdeRey))
                            {
                                contadorPiezasQuePuedenAhogar++;
                            }
                        }
                    }
                    else if (isupper(tipoDerey) == 0)
                    {
                        char piezaDelEnemigo = tablero[i][j]->getRepresentacion();
                        if (isupper(piezaDelEnemigo) != 0)
                        {
                            contadorPIezasEnemigasTotales++;
                            if (tablero[nuevaXDeRey][nuevaYdeRey]->validarMovimiento(i, j, nuevaYdeRey, nuevaYdeRey))
                            {
                                contadorPiezasQuePuedenAhogar++;
                            }
                        }
                    }
                }
            }
        }
        if (contadorPIezasEnemigasTotales == contadorPiezasQuePuedenAhogar)
        {
            return true;
        }
        else
        {
            return false;
        }
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
        cout << endl;
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
        cout << endl;
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
        bool jaqueMate = true;
        imprimirTablero();
        while (jaqueMate)
        {
            if (turnos % 2 == 0)
            {
                cout << jugadorBlancas << endl;
                cout << "Ingrese la pieza mover y su destino: ";
                cin >> comando;
                while (comando.at(1) != '|')
                {
                    cout << "Ingrese una entrada valida\n<Inicial De Pieza>|<Coordenada Inicial>-<Coordenada destino>";
                    cin >> comando;
                }
                while (comando.size() != 7)
                {
                    cout << "Ingrese una entrada valida\n<Inicial De Pieza>|<Coordenada Inicial>-<Coordenada destino>";
                    cin >> comando;
                }
                comando.at(2) = toupper(comando.at(2));
                comando.at(5) = toupper(comando.at(5));
                if (comando == salida)
                {
                    jaqueMate = false;
                }
                else
                {
                    xActual = comando.at(3) - 48;
                    yActual = comando.at(2) - 65;
                    xDestino = comando.at(6) - 48;
                    yDestino = comando.at(5) - 65;
                    while (xDestino < 0 || xDestino > 7 || yDestino < 0 || yDestino > 7)
                    {
                        cout << "No se puede, fuera de los limites. \nCoordenada de nuevo-> ";
                        cin >> comando;
                        while (comando.size() != 7)
                        {
                            cout << "Ingrese una entrada valida\n<Inicial De Pieza>|<Coordenada Inicial>-<Coordenada destino>";
                            cin >> comando;
                        }
                        comando.at(2) = toupper(comando.at(2));
                        comando.at(5) = toupper(comando.at(5));
                        xActual = comando.at(3) - 48;
                        yActual = comando.at(2) - 65;
                        xDestino = comando.at(6) - 48;
                        yDestino = comando.at(5) - 65;
                    }
                    while (tablero[xActual][yActual] == NULL)
                    {
                        cout << "No se puede, no pieza en la posicion ingresada. \nCoordenada de nuevo-> ";
                        cin >> comando;
                        while (comando.size() != 7)
                        {
                            cout << "Ingrese una entrada valida\n<Inicial De Pieza>|<Coordenada Inicial>-<Coordenada destino>";
                            cin >> comando;
                        }
                        comando.at(2) = toupper(comando.at(2));
                        comando.at(5) = toupper(comando.at(5));
                        xActual = comando.at(3) - 48;
                        yActual = comando.at(2) - 65;
                        xDestino = comando.at(6) - 48;
                        yDestino = comando.at(5) - 65;
                    }

                    while (xActual < 0 || xActual > 7 || yActual < 0 || yActual > 7)
                    {
                        cout << "No se puede, fuera de los limites. \nCoordenada de nuevo->  ";
                        cin >> comando;
                        while (comando.size() != 7)
                        {
                            cout << "Ingrese una entrada valida\n<Inicial De Pieza>|<Coordenada Inicial>-<Coordenada destino>";
                            cin >> comando;
                        }
                        comando.at(2) = toupper(comando.at(2));
                        comando.at(5) = toupper(comando.at(5));
                        xActual = comando.at(3) - 48;
                        yActual = comando.at(2) - 65;
                        xDestino = comando.at(6) - 48;
                        yDestino = comando.at(5) - 65;
                    }
                    int xNuevaDestino = comando.at(6) - 48;
                    int yNuevaDestino = comando.at(5) - 65;
                    if (Rey *r = dynamic_cast<Rey *>(tablero[xActual][yActual])) //VALIDACION PARA ENROCAR
                    {
                        if (Torre *t = dynamic_cast<Torre *>((tablero[xNuevaDestino][yNuevaDestino])))
                        {
                            if (enrocar(xActual, yActual, xNuevaDestino, yNuevaDestino, tablero))
                            {
                                imprimirTablero();
                                turnos++;
                            }
                        }
                        else if (ahogado(tablero, 'K', xDestino, yDestino))
                        {
                            cout << "Rey ahogado, no se pueden realizar movimientos. Juego terminado\nbai";
                            jaqueMate = false;
                        }
                        else if (tablero[xActual][yActual]->movimiento(xNuevaDestino, yNuevaDestino, xActual, yActual))
                        {
                            imprimirTablero();
                            turnos++;
                        }
                    }
                    else if (Peon *p = dynamic_cast<Peon *>((tablero[xActual][yActual]))) //CORONAR
                    {
                        if (coronarPeon(xNuevaDestino, yNuevaDestino, xActual, yActual, 'P', tablero))
                        {
                            imprimirTablero();
                            turnos++;
                        }
                        else if (tablero[xActual][yActual]->movimiento(xNuevaDestino, yNuevaDestino, xActual, yActual))
                        {
                            imprimirTablero();
                            turnos++;
                        }
                    }
                    else if (tablero[xActual][yActual]->movimiento(xNuevaDestino, yNuevaDestino, xActual, yActual))
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
                cout << "Ingrese la pieza a mover y su destino: ";
                cin >> comando;
                while (comando.size() != 7)
                {
                    cout << "Ingrese una entrada valida\n<Inicial De Pieza>|<Coordenada Inicial>-<Coordenada destino>";
                    cin >> comando;
                }
                while (comando.at(1) != '|')
                {
                    cout << "Ingrese una entrada valida\n<Inicial De Pieza>|<Coordenada Inicial>-<Coordenada destino>";
                    cin >> comando;
                }
                comando.at(2) = toupper(comando.at(2));
                comando.at(5) = toupper(comando.at(5));
                if (comando == salida)
                {
                    jaqueMate = false;
                }
                else
                {
                    xActual = comando.at(3) - 48;
                    yActual = comando.at(2) - 65;
                    xDestino = comando.at(6) - 48;
                    yDestino = comando.at(5) - 65;
                    while (xDestino < 0 || xDestino > 7 || yDestino < 0 || yDestino > 7)
                    {
                        cout << "No se puede, fuera de los limites. \nCoordenada de nuevo-> ";
                        cin >> comando;
                        while (comando.size() != 7)
                        {
                            cout << "Ingrese una entrada valida\n<Inicial De Pieza>|<Coordenada Inicial>-<Coordenada destino>";
                            cin >> comando;
                        }
                        comando.at(2) = toupper(comando.at(2));
                        comando.at(5) = toupper(comando.at(5));
                        xActual = comando.at(3) - 48;
                        yActual = comando.at(2) - 65;
                        xDestino = comando.at(6) - 48;
                        yDestino = comando.at(5) - 65;
                    }
                    while (tablero[xActual][yActual] == NULL)
                    {
                        cout << "No se puede, no pieza en la posicion ingresada. \nCoordenada de nuevo-> ";
                        cin >> comando;
                        while (comando.size() != 7)
                        {
                            cout << "Ingrese una entrada valida\n<Inicial De Pieza>|<Coordenada Inicial>-<Coordenada destino>";
                            cin >> comando;
                        }
                        comando.at(2) = toupper(comando.at(2));
                        comando.at(5) = toupper(comando.at(5));
                        xActual = comando.at(3) - 48;
                        yActual = comando.at(2) - 65;
                        xDestino = comando.at(6) - 48;
                        yDestino = comando.at(5) - 65;
                    }

                    while (xActual < 0 || xActual > 7 || yActual < 0 || yActual > 7)
                    {
                        cout << "No se puede, fuera de los limites. \nCoordenada de nuevo->  ";
                        cin >> comando;
                        while (comando.size() != 7)
                        {
                            cout << "Ingrese una entrada valida\n<Inicial De Pieza>|<Coordenada Inicial>-<Coordenada destino>";
                            cin >> comando;
                        }
                        comando.at(2) = toupper(comando.at(2));
                        comando.at(5) = toupper(comando.at(5));
                        xActual = comando.at(3) - 48;
                        yActual = comando.at(2) - 65;
                        xDestino = comando.at(6) - 48;
                        yDestino = comando.at(5) - 65;
                    }
                    int xNuevaDestino = comando.at(6) - 48;
                    int yNuevaDestino = comando.at(5) - 65;
                    if (Rey *r = dynamic_cast<Rey *>(tablero[xActual][yActual])) //VALIDACION PARA ENROCAR
                    {
                        if (Torre *t = dynamic_cast<Torre *>((tablero[xNuevaDestino][yNuevaDestino])))
                        {
                            if (enrocar(xActual, yActual, xNuevaDestino, yNuevaDestino, tablero))
                            {
                                imprimirTablero();
                                turnos++;
                            }
                        }
                        if (ahogado(tablero, 'k', xDestino, yDestino))
                        {
                            cout << "Rey ahogado, no se pueden realizar movimientos. Juego terminado\nbai";
                            jaqueMate = false;
                        }
                        else if (tablero[xActual][yActual]->movimiento(xNuevaDestino, yNuevaDestino, xActual, yActual))
                        {
                            imprimirTablero();
                            turnos++;
                        }
                    }
                    else if (Peon *p = dynamic_cast<Peon *>((tablero[xActual][yActual]))) //CORONAR
                    {
                        if (coronarPeon(xNuevaDestino, yNuevaDestino, xActual, yActual, 'P', tablero))
                        {
                            imprimirTablero();
                            turnos++;
                        }
                        else if (tablero[xActual][yActual]->movimiento(xNuevaDestino, yNuevaDestino, xActual, yActual))
                        {
                            imprimirTablero();
                            turnos++;
                        }
                    }
                    else if (tablero[xActual][yActual]->movimiento(xNuevaDestino, yNuevaDestino, xActual, yActual))
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
            int contadorDeReyes = 0;
            int contadorPiezasBalncas = 0;
            int contadorPiezasNegras = 0;
            int contadorMovidasParaAhogarArey = 0;
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (Rey *r = dynamic_cast<Rey *>(tablero[i][j]))
                    {
                        contadorDeReyes++;
                    }
                }
            }
            if (contadorDeReyes < 2)
            {
                cout << "Jaque mate, juego acabado";
                jaqueMate = false;
            }
        }
    }
    ~Ajedrez(){};
};
#endif
