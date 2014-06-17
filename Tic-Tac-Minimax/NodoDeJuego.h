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

class NodoDeJuego {
    
private:
    
    int profundidad;
    NodoDeJuego *padre;
    int pago;
    
    Tablero tablero;
    
public:
    
    NodoDeJuego();
    NodoDeJuego(NodoDeJuego* padre);
    NodoDeJuego* getPadre();
    void setPadre(NodoDeJuego *nodo);
    
    bool estaLibre(int x, int y);
    bool colocar(int j, int x, int y);
    
    void imprimir();
    
};

#endif /* defined(__Tic_Tac_Minimax__NodoDeJuego__) */