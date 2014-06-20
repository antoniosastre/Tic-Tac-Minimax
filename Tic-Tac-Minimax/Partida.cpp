//
//  Partida.cpp
//  Tic-Tac-Minimax
//
//  Created by Antonio Sastre on 17/06/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#include "Partida.h"
#include "Tablero.h"

using namespace std;

Partida::Partida(){
    
    
    
    
    
}

void Partida::sacarHijos(NodoDeJuego nodo, int j){

    
    for (int x = 0; x < ANCHO; x++) {
        for (int y = 0; y < ALTO; y++) {
            
            if (nodo.estaLibre(x, y)) {
                NodoDeJuego nuevo;
                nuevo.ponerPadre(nodo);
                nuevo.colocar(j, x, y);
                partida.push_back(nuevo);
                
               // cout << partida.size() << endl;
                //partida.back().imprimir();
                
                //cout << endl << endl;
                
                int nj;
                if (j==1) {
                    nj=2;
                }else{
                    nj=1;
                }
                if(nuevo.ganado()==0) sacarHijos(nuevo, nj);
            }
            
        }
    }
    
}

void Partida::desarrollar(NodoDeJuego nodo){
    
    sacarHijos(nodo);
    
}

long Partida::nnodos(){
    return partida.size();
}

int Partida::pagoMaxiMin(){
    
    int maxProfundidad = 0;
    
    for (NodoDeJuego nodo : partida) {
        if (nodo.profundidad > maxProfundidad) maxProfundidad = nodo.profundidad;
    }
    
    cout << maxProfundidad;
    
    for (int i = maxProfundidad; i > 0; i--) {
        if (i%2==0) {
            calcularPagoMax(i);
        }else if(i%2==1){
            calcularPagoMin(i);
        }
        cout << endl << "#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#"<< endl;
    }
    
    return -1;
}

void Partida::calcularPagoMin(int nivel){
    
    vector<NodoDeJuego> mismoPadre;
    
    for (NodoDeJuego nodo1 : partida) {
        if (nodo1.profundidad == nivel && !nodo1.visitado) {
            mismoPadre.push_back(nodo1);
            nodo1.visitado=true;
            for (NodoDeJuego nodo2 : partida) {
                if (nodo1.padre == nodo2.padre && !nodo2.visitado) {
                    mismoPadre.push_back(nodo2);
                    nodo2.visitado=true;
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
            
            mismoPadre.clear();
            
            cout << min;
            
            
            
        }
    }
    
}

void Partida::calcularPagoMax(int nivel){
    
    vector<NodoDeJuego> mismoPadre;
    
    for (NodoDeJuego nodo1 : partida) {
        if (nodo1.profundidad == nivel && !nodo1.visitado) {
            mismoPadre.push_back(nodo1);
            nodo1.visitado=true;
            for (NodoDeJuego nodo2 : partida) {
                if (nodo1.padre == nodo2.padre && !nodo2.visitado) {
                    mismoPadre.push_back(nodo2);
                    nodo2.visitado=true;
                }
            }
        }
    }
    
    int max = 0;
    
    if (mismoPadre.size()>0) {
        max = mismoPadre[0].pago;
    }
    
    for (NodoDeJuego nodo : mismoPadre){
        if (nodo.pago>max) max = nodo.pago;
    }
    
    mismoPadre[0].padre->pago = max;
    
    mismoPadre.clear();
    
    cout << max;
    
}





