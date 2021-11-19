#ifndef SRC_NODO_H_
#define SRC_NODO_H_

#include <iostream>
#include "jugador.h"
class Nodo{
private:
        Jugador* dato;
        Nodo* siguiente;

public:
        Nodo();
        void setDato(Jugador* dato);
        virtual ~Nodo();
        Jugador* getDato();
        Nodo* getSiguiente();
        void setSiguiente(Nodo* nodo);
    
};

#endif 

