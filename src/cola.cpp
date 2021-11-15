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

void Cola::ColaDestruir(void destruirDato(void *)){
    while(this->front->getSiguiente() != NULL){
        
        Nodo* aux = this->front;

        if(destruirDato){
            destruirDato(aux->getDato());
        }
        
        this->front = aux->getSiguiente();
    
        delete aux;
    }

    delete this;
}

Jugador* Cola::frente(){
    return this->front->getDato();
}

void Cola::acolar(Jugador* elemento){

    Nodo* aux = new Nodo(elemento);
    if(this->tamanio == 0) {
    	this->front = aux;
    } else {
    	this->end->setSiguiente(aux);
    	this->end = aux;
    }
    this->tamanio += 1;
}

Jugador* Cola::desacolar(){
    Nodo *aux = this->front; //aux = nodo1
    Jugador *dato = aux->getDato();
  
    this->front = aux->getSiguiente(); //front = nodo2 -> nodo2 = nodo1
    this->tamanio -= 1;
    
    delete aux; //elimino el front original
    return dato; //devuelvo el dato que tenia nodo1
}

bool Cola::vacia(){
    if (this->tamanio == 0){
        return true;
    }

    else{
        return false;
    }
}

