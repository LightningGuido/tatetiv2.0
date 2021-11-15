/*
 * cola.h
 *
 *  Created on: Nov 11, 2021
 *      Author: guido
 */

#ifndef SRC_COLA_H_
#define SRC_COLA_H_
#include <iostream>
#include "Nodo.h"

class Cola{

    private:
        size_t tamanio;
        Nodo* front;
        Nodo* end;

    public:

        Cola();
        /*Crea la cola
        PRE: no tiene
        POST: una cola vacia preparada para ser usada*/
        void ColaDestruir(void destruirDato(void *));
        /* Destruye la cola
        PRE: la cola debe haberi sido creada
        POST: no tiene*/
        Jugador* frente();
        /*Retorna el primer elemento de la cola
        PRE: la cola, ya creada, no debe estar vacia
        POST: no tiene*/
        void acolar(Jugador* aux);
        /* Da de alta en la cola a un elemento pasado por argumento
        PRE: la cola debe haber sido creada
        POST: la cola modificada con la inserciòn del nuevo elemento al fondo*/
        Jugador* desacolar();
        /*Elimina el elemento del frente de la cola
        PRE: la cola, ya creada, no debe estar vacia
        POST: cola modificada por la eliminacion del elemento del frente*/
        bool vacia();
        /* Devuelve un valor logico indicando si la cola esta vacia
        PRE: la cola debe haber sido creada
        POST: no tiene */
        Jugador* siguiente();
        void acolarFrente(Jugador* nuevo);
};

#endif /*SRC_COLA_H_*/
