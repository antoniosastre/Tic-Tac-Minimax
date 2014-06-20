//
//  JugadorMin.cpp
//  Tic-Tac-Minimax
//
//  Created by Antonio Sastre on 17/06/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#include "JugadorMin.h"

JugadorMin::JugadorMin(){
    
    
}

void JugadorMin::calcularPagoMin(Partida p, int nivel){
    
    vector<NodoDeJuego> mismoPadre;
    
    for (NodoDeJuego nodo1 : p.partida) {
        if (nodo1.profundidad == nivel && !nodo1.visitado) {
            mismoPadre.push_back(nodo1);
            nodo1.visitado=true;
            for (NodoDeJuego nodo2 : p.partida) {
                if (nodo1.padre == nodo2.padre && !nodo2.visitado) {
                    mismoPadre.push_back(nodo2);
                    nodo1.visitado=true;
                }
            }
        }
    }
    
    int min = 0;
    
    if (mismoPadre.size()>0) {
        min = mismoPadre[0].pago;
    }
    
    for (NodoDeJuego nodo : mismoPadre){
        if (nodo.pago<min) min = nodo.pago;
    }
    
    mismoPadre[0].padre->pago = min;
    cout << min;
    
}