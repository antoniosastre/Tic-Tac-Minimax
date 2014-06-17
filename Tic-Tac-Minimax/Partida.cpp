//
//  Partida.cpp
//  Tic-Tac-Minimax
//
//  Created by Antonio Sastre on 17/06/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#include "Partida.h"
#include "Tablero.h"

Partida::Partida(){
    
    
    
    
    
}

void Partida::sacarHijos(NodoDeJuego* nodo, int j){
    
    for (int x = 0; x < ANCHO; x++) {
        for (int y = 0; y < ALTO; y++) {
            
            if (nodo->estaLibre(x, y)) {
                NodoDeJuego nuevo(nodo);
                nuevo.colocar(j, x, y);
                partida.push_back(nuevo);
                
                //partida.back().imprimir();
                
                cout << endl;
                
                int nj;
                if (j==1) {
                    nj=2;
                }else{
                    nj=1;
                }
                
                sacarHijos(&nuevo, nj);
            }
            
        }
    }
    
}

void Partida::desarrollar(NodoDeJuego* nodo){
    
    sacarHijos(nodo);
    
}

long Partida::nnodos(){
    return partida.size();
}