/*
 * cola.h
 *
 *  Created on: Nov 11, 2021
 *      Author: guido
 */

#ifndef SRC_COLA_H_
#define SRC_COLA_H_
#include <iostream>
#include "jugador.h"
#include "Nodo.h"

class Cola{

    private:
        size_t tamanio;
        Nodo* front;
        Nodo* end;

    public:
        /*
        PRE: -
        POST: crea una cola vacia preparada para ser usada y con tamanio 0*/
        Cola();
        /*
        PRE: -
        POST: Destruye la cola */
        virtual ~Cola();
        /*
        PRE: la cola, ya creada, no debe estar vacia
        POST: Retorna el primer elemento de la cola*/
        Jugador* frente();
        /*
        PRE: -
        POST: Da de alta en la cola a un elemento pasado por argumento,
        devuelve la cola modificada con la inserciòn del nuevo elemento al fondo*/
        void acolar(Jugador* dato);
        /*
        PRE: la cola, ya creada, no debe estar vacia
        POST: Elimina el elemento del frente de la cola y
        devuelve cola modificada por la eliminacion del elemento del frente*/
        Jugador* desacolar();
        /*
        PRE: -
        POST: Devuelve un true si la cola esta vacia y false en caso contrario */
        bool vacia();
        /*PRE:-
        * POST: Devuelve el elemento siguiente al elemento que se encuentra en el frente de la cola
        */
        Jugador* siguiente();
        /*PRE:-
        * POST: Devuelve el tamaño de la cola
        */
        size_t getTamanio();
};

#endif /*SRC_COLA_H_*/
