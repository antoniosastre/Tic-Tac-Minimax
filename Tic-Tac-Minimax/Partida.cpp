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

void Partida::sacarHijos(long nodopadre, int jugador){

    
    for (int x = 0; x < ANCHO; x++) {
        for (int y = 0; y < ALTO; y++) {
            
            if (partida[nodopadre].estaLibre(x, y)) {
                NodoDeJuego nuevo;
                nuevo.ponerPadre(nodopadre, partida);
                nuevo.colocar(jugador, x, y);
                partida.push_back(nuevo);
                
               // cout << partida.size() << endl;
                //partida.back().imprimir();
                
                //cout << endl << endl;
                
                int nj;
                if (jugador==1) {
                    nj=2;
                }else{
                    nj=1;
                }
                if(nuevo.ganado()==0) sacarHijos(partida.size()-1, nj);
            }
            
        }
    }
    
}

void Partida::desarrollar(){
    
    NodoDeJuego primero;
    
    partida.push_back(primero);
    
    sacarHijos(0, 1);
    
}

long Partida::nnodos(){
    return partida.size();
}

void Partida::pagoMaxiMin(){
    
    int maxProfundidad = 0;
    
    for (NodoDeJuego nodo : partida) {
        if (nodo.profundidad > maxProfundidad) maxProfundidad = nodo.profundidad;
    }
    
    for (int i = maxProfundidad; i > 0; i--) {
        if (i%2==0) {
            cout << endl << "Pagos del nivel "<<  i << " a su superior." << endl;
            calcularPagoMin(i);
        }else if(i%2==1){
            cout << endl << "Pagos del nivel "<<  i << " a su superior." << endl;
            calcularPagoMax(i);
        }
        cout << endl << "#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#"<< endl;
    }
    
}

void Partida::calcularPagoMin(int nivel){
    
    vector<NodoDeJuego> mismoPadre;
    
    for (int j=0 ; j < partida.size() ; j++) {
        if (partida[j].profundidad == nivel && !partida[j].visitado) {
           partida[j].visitado=true;
            mismoPadre.push_back(partida[j]);
            for (int k=0 ; k < partida.size() ; k++) {
                if (partida[j].padre == partida[k].padre && !partida[k].visitado) {
                    partida[k].visitado=true;
                    mismoPadre.push_back(partida[k]);

                }
            }
            
            int min = 0;
            
            if (mismoPadre.size()>0) {
                min = mismoPadre[0].pago;
            }
            
            for (NodoDeJuego nodo : mismoPadre){
                if (nodo.pago<min) min = nodo.pago;
            }
            
            partida[mismoPadre[0].padre].pago=min;
            
            mismoPadre.clear();
            
            cout << min;
            
            
            
        }
    }
    
}

void Partida::calcularPagoMax(int nivel){
    
    vector<NodoDeJuego> mismoPadre;
    
    for (int j=0 ; j < partida.size() ; j++) {
        if (partida[j].profundidad == nivel && !partida[j].visitado) {
            partida[j].visitado=true;
            mismoPadre.push_back(partida[j]);
            for (int k=0 ; k < partida.size() ; k++) {
                if (partida[j].padre == partida[k].padre && !partida[k].visitado) {
                    partida[k].visitado=true;
                    mismoPadre.push_back(partida[k]);
                    
                }
            }

    
    int max = 0;
    
    if (mismoPadre.size()>0) {
        max = mismoPadre[0].pago;
    }
    
    for (NodoDeJuego nodo : mismoPadre){
        if (nodo.pago>max) max = nodo.pago;
    }
    
    
    partida[mismoPadre[0].padre].pago=max;
    
    mismoPadre.clear();
    
    cout << max;
            
        }
    }
    
}

int Partida::getPagoCero(){
    return partida[0].pago;
}





