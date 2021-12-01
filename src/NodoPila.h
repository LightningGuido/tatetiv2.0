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

    /* PRE:-
    * POST: Recibe un dato por parametro y lo setea como el dato Ultimo del NodoPila
    */
    NodoPila(Tablero* dato);
    /* PRE:-
    * POST: Destruye el NodoPila
    */
    virtual ~NodoPila();
    /* PRE:-
    * POST: Devuelve el dato Ultimo del NodoPila
    */
    Tablero* getUltimo();
    /* PRE:-
    * POST: Devuelve el NodoPila Siguiente del NodoPila
    */
    NodoPila* getSiguiente();
    /* PRE:-
    * POST: Recibe un NodoPila por parametro y lo setea como el Siguiente del NodoPila
    */
    void setSiguiente(NodoPila* nodo);
    
};

#endif 
