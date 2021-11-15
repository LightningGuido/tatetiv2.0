/*
 * pila.h
 *
 *  Created on: Nov 11, 2021
 *      Author: guido
 */

#ifndef SRC_PILA_H_
#define SRC_PILA_H_
#include <iostream>
#include "Nodo.h"

class Pila{
    private:
        Nodo* tope;
        size_t tamanio;
    
    public:

        Pila();
        /* Crea la pila
        PRE: no tiene
        POST: una pila vacia preparada para ser usada */
        void pilaDestruir(void destruirDato(void *));
        /*Destruye la pila
        PRE: la pila debe haber sido creada
        POST: no tiene */
        void push(void* dato);
        /*Realiza el alta en la pila de un elemento pasado por argumento
        PRE: la pila debe haber sido creada
        POST: la pila modificada cpn la insercion del nuevo elemento en el tope */
        void* pop();
        /* Elimina el elemento del tope de la misma
        PRE: la pila, ya creada, no debe estar vacia
        POST: una pila modificada por la eliminacion del elemento del tope*/
        void* top();
        /* Retorna el valor del tope de la pila
        PRE: la pila, ya creada, no debe estar vacia
        POST: no tiene*/
        bool vacia();
        /* Devuelve un valor logico indicando si a pila esta vacia
        PRE: la pila debe haber sido creada
        POST: no tiene*/
        void setTope(Nodo* nodo);
        /*Setea como tope de la Pila a nodo que se pasa como parametro
        PRE: la pila debe haber sido creada
        POST: la pila modificada con un nuevo tope, y el tope anterior como siguiente del tope seteado */
};


#endif /* SRC_PILA_H_ */