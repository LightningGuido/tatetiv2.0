#ifndef SRC_NODOPILA_H_
#define SRC_NODOPILA_H_

#include <iostream>
#include "tablero.h"
#include "Nodo.h"
class NodoPila{
private:
        Tablero* ultimo;
        NodoPila* siguiente;

public:
    NodoPila(Tablero* dato);
    void nodoDestruir();
    Tablero* getUltimo();
    NodoPila* getSiguiente();
    void setSiguiente(NodoPila* nodo);
    
};

#endif 