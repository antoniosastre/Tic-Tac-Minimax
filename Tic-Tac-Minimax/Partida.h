//
//  Partida.h
//  Tic-Tac-Minimax
//
//  Created by Antonio Sastre on 17/06/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#ifndef __Tic_Tac_Minimax__Partida__
#define __Tic_Tac_Minimax__Partida__

#include <iostream>
#include "JugadorMax.h"
#include "JugadorMin.h"
#include <vector>
#include "NodoDeJuego.h"

using namespace std;

class Partida {
    
private:
    
    JugadorMax max;
    JugadorMin min;

    vector<NodoDeJuego> partida;
    
    void sacarHijos(NodoDeJuego* nodo, int j=1);
    
    
    
    
    
public:
    
    Partida();
    
    bool ganado();
    
    void desarrollar(NodoDeJuego* nodo);
    
    long nnodos();
    
};

#endif /* defined(__Tic_Tac_Minimax__Partida__) */
