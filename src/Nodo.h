#ifndef SRC_NODO_H_
#define SRC_NODO_H_

#include <iostream>
#include "jugador.h"
class Nodo{
private:
        Jugador* dato;
        Nodo* siguiente;

public:
        /* PRE:-
        * POST: Crea un nodo e inicializa el dato y el dato siguiente como NULL
        */
        Nodo();
        /* PRE:
        * POST:Recibe un dato por parametro y lo setea como dato del Nodo
        */
        void setDato(Jugador* dato);
        /* PRE:
        * POST: Destruye al Nodo
        */
        virtual ~Nodo();
        /* PRE:
        * POST: Devuelve el dato del Nodo
        */
        Jugador* getDato();
        /* PRE:
        * POST: Devuelve el dato Siguiente del Nodo
        */
        Nodo* getSiguiente();
        /* PRE:
        * POST: Recibe un dato por parametro y lo setea como dato Siguiente del Nodo
        */
        void setSiguiente(Nodo* nodo);
    
};

#endif 

