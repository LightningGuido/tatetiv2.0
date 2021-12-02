/*
 * pila.h
 *
 *  Created on: Nov 11, 2021
 *      Author: guido
 */

#ifndef SRC_PILA_H_
#define SRC_PILA_H_
#include <iostream>

#include "NodoPila.h"
#include "tablero.h"

class Pila{
    private:
        NodoPila* tope;
        int tamanio;
    
    public:
        /*
        PRE: -
        POST: Crea una pila vacia preparada para ser usada */
        Pila();
        /*
        PRE: -
        POST: Destruye la pila */
        virtual ~Pila();
        /*
        PRE: -
        POST: Realiza el alta en la pila de un elemento pasado por argumento y devulve
        la pila modificada con la insercion del nuevo elemento en el tope */
        void push(Tablero* dato);
        /*
        PRE: la pila, ya creada, no debe estar vacia
        POST: Elimina el elemento del tope de la misma y devuelve
        una pila modificada por la eliminacion del elemento del tope*/
        Tablero* pop();
        /*
        PRE: la pila, ya creada, no debe estar vacia
        POST:  Retorna el valor del tope de la pila*/
        Tablero* top();
        /*
        * PRE: -
        * POST: Devuelve el valor logico true si la pila esta vacia, false en caso contrario
        */
        bool vacia();
        /*
        * PRE: -
        * POST: Setea como tope de la Pila al NodoPila que se pasa como parametro y
        * devuelve la pila modificada con un nuevo tope, y el tope anterior como siguiente del tope seteado */
        void setTope(NodoPila* ultimo);

};


#endif /* SRC_PILA_H_ */
