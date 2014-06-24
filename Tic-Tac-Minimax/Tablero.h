//
//  Tablero.h
//  Tic-Tac-Minimax
//
//  Created by Antonio Sastre on 17/06/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#ifndef __Tic_Tac_Minimax__Tablero__
#define __Tic_Tac_Minimax__Tablero__

#include <iostream>

const int ALTO = 3;
const int ANCHO = 3;

class Tablero {
    
private:
    
    
    int libres;
    
public:
    
    //Se almacena 1 para el jugador 1. 2 - Jugador 2, 0 - Libre.
    int mesa[3][3];
    
    Tablero();
    Tablero(Tablero const &otro);
    Tablero& operator=(const Tablero & otro);
    
    //Inserta la ficha del jugador j en la posición x,y
    bool insertar(int j, int x, int y);
    
    //Devuelve si el tablero está lleno de fichas.
    bool lleno();
    
    //Devuelve si la posición indicada está libre.
    bool estaLibre(int x, int y);
    
    //Imprime el tablero.
    void imprimir();
    
    //Devuelve si hay algún ganador. 0-Ninguno/empate. 1 el J1, 2 el J2.
    int ganado();
    
    
};

#endif /* defined(__Tic_Tac_Minimax__Tablero__) */
