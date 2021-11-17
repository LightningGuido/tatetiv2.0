/*
 * cola.cpp
 *
 *  Created on: Nov 11, 2021
 *      Author: cata
 */

#include "cola.h"

Cola::Cola(){
    this->tamanio = 1;
    this->front = NULL;
    this->end = NULL;
}

void Cola::ColaDestruir(){
    
    Nodo* aux = this->front;
    if(!vacia()){
        while(this->front != NULL){
        
            this->front = aux->getSiguiente();
            delete(aux);

            aux = this->front;
        }
    }
    this->end = NULL;
    this->tamanio = 1;
    delete this;
}

Jugador* Cola::frente(){
    return this->front->getDato();
}

void Cola::acolar(Nodo* elemento){


    if(this->tamanio == 1 && this->front == NULL && this->end == NULL) {
    	this->front = elemento;
        this->end = elemento; //si hay un solo elemento: ese elemento es front y end
    } else {
    	this->end->setSiguiente(elemento);
    	this->end = this->end->getSiguiente();
    }
    this->tamanio += 1;
    //std::cout << "el primero es: " << this->front->getNombre() << std::endl;
    //std::cout << "el ultimo  es: " << this->end->getNombre() << std::endl;
}

Nodo* Cola::desacolar(){
    Nodo* aux = this->front; //aux = nodo1
    
    this->front = this->front->getSiguiente(); //front = nodo2 -> nodo2 = nodo1
    this->tamanio -= 1;
    
    return aux; //devuelvo el dato que tenia nodo1
}

bool Cola::vacia(){
    if (this->tamanio == 1 && this->front == NULL && this->end == NULL){
        return true;
    }

    else{
        return false;
    }
}

Jugador* Cola::siguiente(){
    return this->front->getSiguiente()->getDato();
}

/*void Cola::acolarFrente(Jugador* nuevo){
    
    //Jugador *aux = desacolar();

    if(this->tamanio == 1){
        this->front = nuevo;
    }
    else{
        nuevo->setJugadorSiguiente(this->front);
        this->front = nuevo;
    }
    this->tamanio += 1;
}*/
