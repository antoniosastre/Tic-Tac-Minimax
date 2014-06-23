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
    
    int mesa[3][3];
    
    Tablero();
    Tablero(Tablero const &otro);
    Tablero& operator=(const Tablero & otro);
    
    bool insertar(int j, int x, int y);
    bool lleno();
    
    bool estaLibre(int x, int y);
    
    void imprimir();
    
    int ganado();
    
    
};

#endif /* defined(__Tic_Tac_Minimax__Tablero__) */
