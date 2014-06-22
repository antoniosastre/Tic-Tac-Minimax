//
//  NodoDeJuego.h
//  Tic-Tac-Minimax
//
//  Created by Antonio Sastre on 17/06/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#ifndef __Tic_Tac_Minimax__NodoDeJuego__
#define __Tic_Tac_Minimax__NodoDeJuego__

#include <iostream>
#include "Tablero.h"
#include <vector>

using namespace std;

class NodoDeJuego {
    
private:
    
    Tablero tablero;
    
public:
    
    bool visitado;
    int profundidad;
    long padre;
    int pago;
    
    NodoDeJuego();
    NodoDeJuego(NodoDeJuego const &copia);
    long getPadre();
    void ponerPadre(long papa, vector<NodoDeJuego> &partida);
    
    bool estaLibre(int x, int y);
    bool colocar(int j, int x, int y);
    
    void imprimir();
    
    int ganado();
    
};

#endif /* defined(__Tic_Tac_Minimax__NodoDeJuego__) */
