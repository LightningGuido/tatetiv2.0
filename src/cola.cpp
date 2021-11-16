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

void Cola::ColaDestruir(){
    
    Nodo* aux = this->front;
    if(!vacia()){
        while(this->front != NULL){
        
            this->front = this->front->getSiguiente();
            delete aux->getDato();
            delete aux;

            aux = this->front;
        }
    }
    this->end = NULL;
    this->tamanio = 0;
    delete this;
}

Jugador* Cola::frente(){
    return this->front->getDato();
}

void Cola::acolar(Nodo* elemento){

    
    if(this->tamanio == 0) {
    	this->front = elemento;
    } else {
    	this->end->setSiguiente(elemento);
    	this->end = elemento;
    }
    this->tamanio += 1;
}

Nodo* Cola::desacolar(){
    Nodo *aux = this->front; //aux = nodo1
    
    this->front = aux->getSiguiente(); //front = nodo2 -> nodo2 = nodo1
    this->tamanio -= 1;
    
    return aux; //devuelvo el dato que tenia nodo1
}

bool Cola::vacia(){
    if (this->tamanio == 0){
        return true;
    }

    else{
        return false;
    }
}

Jugador* Cola::siguiente(){
    return this->front->getSiguiente()->getDato();
}

void Cola::acolarFrente(Jugador* nuevo){
    Nodo *aux = new Nodo(nuevo);

    if(this->tamanio == 0){
        this->front = aux;
    }
    else{
        aux->setSiguiente(this->front);
        this->front = aux;
    }
    this->tamanio += 1;
}