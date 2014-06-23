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
    
    maxProfundidad = 0;
    
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

void Partida::pagoMaxiMin2(){
    
    maxProfundidad = 0;
    
    for (NodoDeJuego nodo : partida) {
        if (nodo.profundidad > maxProfundidad) maxProfundidad = nodo.profundidad;
    }
    
    for (int i = maxProfundidad; i > 0; i--) {
        if (i%2==0) {
            //cout << endl << "Pagos del nivel "<<  i << " a su superior." << endl;
            calcularPagoMin2(i);
        }else if(i%2==1){
            //cout << endl << "Pagos del nivel "<<  i << " a su superior." << endl;
            calcularPagoMax2(i);
        }
        //cout << endl << "#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#"<< endl;
    }
    
}

void Partida::calcularPagoMin(int nivel){
    
    vector<NodoDeJuego> mismoPadre;
    vector<NodoDeJuego> mismoNivel;
    
    for (int j=0 ; j < partida.size() ; j++) {
        if (partida[j].profundidad == nivel){
            mismoNivel.push_back(partida[j]);
        }
    }
    
    for (int j=0 ; j < mismoNivel.size() ; j++) {
        if (!mismoNivel[j].visitado) {
            mismoNivel[j].visitado=true;
            mismoPadre.push_back(mismoNivel[j]);
            for (int k=0 ; k < mismoNivel.size() ; k++) {
                if (mismoNivel[j].padre == mismoNivel[k].padre && !mismoNivel[k].visitado) {
                    mismoNivel[k].visitado=true;
                    mismoPadre.push_back(mismoNivel[k]);
                    
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
            
            //cout << min;
            
            
            
        }
    }
    
}

void Partida::calcularPagoMax(int nivel){
    
    vector<NodoDeJuego> mismoPadre;
    vector<NodoDeJuego> mismoNivel;
    
    for (int j=0 ; j < partida.size() ; j++) {
        if (partida[j].profundidad == nivel){
            mismoNivel.push_back(partida[j]);
        }
    }
    
    for (int j=0 ; j < mismoNivel.size() ; j++) {
        if (!mismoNivel[j].visitado) {
            mismoNivel[j].visitado=true;
            mismoPadre.push_back(mismoNivel[j]);
            for (int k=0 ; k < mismoNivel.size() ; k++) {
                if (mismoNivel[j].padre == mismoNivel[k].padre && !mismoNivel[k].visitado) {
                    mismoNivel[k].visitado=true;
                    mismoPadre.push_back(mismoNivel[k]);
                    
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
            
            //cout << max;
            
        }
    }
    
}


void Partida::calcularPagoMax2(int nivel){
    
    vector<NodoDeJuego> mismoNivel;
    
    for (int j=0 ; j < partida.size() ; j++) {
        if (partida[j].profundidad == nivel){
            mismoNivel.push_back(partida[j]);
        }
    }
    
    //long antpadre=-1;
    
    for (int j=0 ; j < mismoNivel.size() ; j++) {
        
        if (partida[mismoNivel[j].padre].pago<mismoNivel[j].pago){
            
            partida[mismoNivel[j].padre].pago=mismoNivel[j].pago;
            
        }
        
//        if( mismoNivel[j].padre != antpadre && antpadre != -1){
//            cout << partida[mismoNivel[j-1].padre].pago;
//            
//        }
//        
//        antpadre=mismoNivel[j].padre;
        
    }
    
}


void Partida::calcularPagoMin2(int nivel){
    
    vector<NodoDeJuego> mismoNivel;
    
    for (int j=0 ; j < partida.size() ; j++) {
        if (partida[j].profundidad == nivel){
            mismoNivel.push_back(partida[j]);
        }
    }

    //long antpadre=-1;
    
    for (int j=0 ; j < mismoNivel.size() ; j++) {
        
        if (partida[mismoNivel[j].padre].pago>mismoNivel[j].pago){
            
            partida[mismoNivel[j].padre].pago=mismoNivel[j].pago;
            
        }
        
//        if( mismoNivel[j].padre != antpadre && antpadre != -1){
//            cout << partida[mismoNivel[j-1].padre].pago;
//            
//        }
//        
//        antpadre=mismoNivel[j].padre;
        
    }

    
}

int Partida::getPagoCero(){
    return partida[0].pago;
}


void Partida::printCamino(int nivel){
    
    if (nivel > maxProfundidad) return;
    
        vector<NodoDeJuego> mismoNivel;
        
        for (int j=0 ; j < partida.size() ; j++) {
            if (partida[j].profundidad == nivel){
                mismoNivel.push_back(partida[j]);
            }
        }
    
    int minomax=0;
    if (mismoNivel.size()>0) {
        minomax=mismoNivel[0].pago;
    }
    
        for (int j=0; j < mismoNivel.size(); j++) {
            if (nivel%2==1 && mismoNivel[j].pago > minomax){
                minomax = mismoNivel[j].pago;
            }else if (nivel%2==0 && mismoNivel[j].pago < minomax){
                minomax = mismoNivel[j].pago;
            }
        }
        
    for (int j=0; j < mismoNivel.size(); j++) {
        if (mismoNivel[j].pago == minomax){
            mismoNivel[j].imprimir();
            printCamino(nivel+1);
            
        }
    }
    
    }


    int Partida::buscarMaxHijoDe(int nodo){
        
        if (partida[nodo].profundidad>=maxProfundidad) return -1;
        vector<NodoDeJuego> mismoPadre;
        vector<NodoDeJuego> mismoNivel;
        vector<int> nodoMismoPadre;
        
        for (int j=0 ; j < partida.size() ; j++) {
            if (partida[j].profundidad == partida[nodo].profundidad+1){
                mismoNivel.push_back(partida[j]);
            }
        }
        
        for (int j=0 ; j < mismoNivel.size() ; j++) {
            if (mismoNivel[j].padre==nodo) {
                mismoNivel[j].visitado=true;
                mismoPadre.push_back(mismoNivel[j]);
            }
            
        }
        
                int max = -1;
                
                if (mismoPadre.size()>0) {
                    max = mismoPadre[0].pago;
                }
                
                for (NodoDeJuego nodo : mismoPadre){
                    if (nodo.pago>max) max = nodo.pago;
                }
                
                
                partida[mismoPadre[0].padre].pago=max;
                
                mismoPadre.clear();
                
                //cout << max;
            

        
        return -1;
    }

    int Partida::buscarMinHijoDe(int nodo){
    
        return -1;
    }

void Partida::printPagos(){
    
    for (int nivel=0 ; nivel <= maxProfundidad ; nivel++) {
        cout << "Pagos para el nivel " << nivel << endl << endl;
        for (int j=0 ; j < partida.size() ; j++) {
            if (partida[j].profundidad == nivel){
                cout << partida[j].pago;
            }
        }
        cout << endl << endl << endl << endl;
    }
    
    
    
    
}

void Partida::printJugada(){
    
    int padre=0;
    int pago = partida[padre].pago;
    
    for (int nivel=1 ; nivel <= maxProfundidad ; nivel++) {
        for (int j=0 ; j < partida.size() ; j++) {
            if (partida[j].padre == padre && partida[j].pago==pago){
                partida[j].imprimir();
                cout << endl;
                padre=j;
                break;
            }
        }
        cout << endl;
    }
    
    
}





