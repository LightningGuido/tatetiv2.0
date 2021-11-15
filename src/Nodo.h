#ifndef SRC_NODO_H_
#define SRC_NODO_H_

#include <iostream>

class Nodo{
    private: 
        void* dato;
        Nodo* siguiente;

    public:

    Nodo(void* dato);
    void nodoDestruir();
    void* getDato();
    Nodo* getSiguiente();
    void setSiguiente(Nodo* nodo);
    
};

#endif 
