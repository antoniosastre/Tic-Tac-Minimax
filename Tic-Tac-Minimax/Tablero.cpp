//
//  Tablero.cpp
//  Tic-Tac-Minimax
//
//  Created by Antonio Sastre on 17/06/14.
//  Copyright (c) 2014 Antonio Sastre. All rights reserved.
//

#include "Tablero.h"

using namespace std;


Tablero::Tablero(){
    
    for (int x = 0; x < ANCHO; x++) {
        for (int y = 0; y < ALTO; y++) {
            mesa[x][y] = 0;
        }
    }
    
    libres = 9;
    
}

Tablero::Tablero(Tablero const &otro){
    
    for (int x = 0; x < ANCHO; x++) {
        for (int y = 0; y < ALTO; y++) {
            mesa[x][y] = otro.mesa[x][y];
        }
    }
    
    libres = otro.libres;
    
}

Tablero& Tablero::operator=(const Tablero & otro){
    
    
    if (this == &otro) return *this;
    
    for (int x = 0; x < ANCHO; x++) {
        for (int y = 0; y < ALTO; y++) {
            mesa[x][y] = otro.mesa[x][y];
        }
    }
    
    libres = otro.libres;
    
    return *this;
    
}

bool Tablero::insertar(int j, int x, int y){
    
    if ( !(libres>0) || !estaLibre(x,y) ) return false;
    
    mesa[x][y] = j;
    
    libres--;
    
    return true;
    
}

bool Tablero::estaLibre(int x, int y){
    
    return mesa[x][y]==0;

}

bool Tablero::lleno(){
    
    return (libres==0);
    
}

void Tablero::imprimir(){
    cout << mesa[0][0] << "|" << mesa[1][0] << "|" << mesa[2][0] << endl;
    cout << "-----" << endl;
    cout << mesa[0][1] << "|" << mesa[1][1] << "|" << mesa[2][1] << endl;
    cout << "-----" << endl;
    cout << mesa[0][2] << "|" << mesa[1][2] << "|" << mesa[2][2] << endl;
    
}

int Tablero::ganado(){
    
    if ((mesa[0][0] == mesa[0][1]) && (mesa[0][1] == mesa[0][2]) && (mesa[0][2] != 0)) return mesa[0][2];
    if ((mesa[1][0] == mesa[1][1]) && (mesa[1][1] == mesa[1][2]) && (mesa[1][2] != 0)) return mesa[1][2];
    if ((mesa[2][0] == mesa[2][1]) && (mesa[2][1] == mesa[2][2]) && (mesa[2][2] != 0)) return mesa[2][2];
    if ((mesa[0][0] == mesa[1][0]) && (mesa[1][0] == mesa[2][0]) && (mesa[2][0] != 0)) return mesa[2][0];
    if ((mesa[0][1] == mesa[1][1]) && (mesa[1][1] == mesa[2][1]) && (mesa[2][1] != 0)) return mesa[2][1];
    if ((mesa[0][2] == mesa[1][2]) && (mesa[1][2] == mesa[2][2]) && (mesa[2][2] != 0)) return mesa[2][2];
    if ((mesa[0][0] == mesa[1][1]) && (mesa[1][1] == mesa[2][2]) && (mesa[2][2] != 0)) return mesa[2][2];
    if ((mesa[0][2] == mesa[1][1]) && (mesa[1][1] == mesa[2][0]) && (mesa[2][0] != 0)) return mesa[2][0];
    
    return 0;
    
}



