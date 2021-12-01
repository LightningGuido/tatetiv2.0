/*
 * cola.cpp
 *
 *  Created on: Nov 11, 2021
 *      Author: cata
 */

#include "cola.h"

Cola::Cola(){
    this->tamanio = 0;
    this->front = NULL;
    this->end = NULL;
}

Cola::~Cola(){
    
    Nodo* aux = NULL;
        while(this->front != NULL){
        	aux = this->front;
            this->front = aux->getSiguiente();
            delete(aux);

        }
}

Jugador* Cola::frente(){
    return this->front->getDato();
}

void Cola::acolar(Jugador* dato){

	Nodo *elemento = new Nodo();
	elemento->setDato(dato);
    if(this->tamanio == 0 && this->front == NULL && this->end == NULL) {
    	this->front = elemento;
        this->end = elemento;
    } else if (this->tamanio == 1){
    	this->front->setSiguiente(elemento);
    	this->end = this->front->getSiguiente();
    }
    else {
    	this->end->setSiguiente(elemento);
    	this->end = this->end->getSiguiente();
    }
    this->tamanio += 1;

}

Jugador* Cola::desacolar(){
    Nodo* aux = this->front;
    Jugador* jugador = aux->getDato();
    
    this->front = this->front->getSiguiente();
    this->tamanio -= 1;
    
    delete aux;
    return jugador;

}

bool Cola::vacia(){
    if (this->tamanio == 0 && this->front == NULL && this->end == NULL){
        return true;
    }

    else{
        return false;
    }
}

Jugador* Cola::siguiente(){
    return this->front->getSiguiente()->getDato();
}


size_t Cola::getTamanio(){
	return this->tamanio;
}
