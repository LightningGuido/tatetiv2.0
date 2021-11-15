/*
 * pila.cpp
 *
 *  Created on: Nov 11, 2021
 *      Author: guido
 */

#include "pila.h"

Pila::Pila(){
    this->tamanio = 0;
    this->tope = NULL;
}
    
void Pila::pilaDestruir(void destruirDato(void *)){
    
    while(this->tope->getSiguiente() != NULL){
        
        Nodo* aux = this->tope;

        if(destruirDato){
            destruirDato(aux->getDato());
        }
        
        this->tope = aux->getSiguiente();
    
        delete aux;
    }

    delete this;
}

void Pila::setTope(Nodo* nodo){
    this->tope = nodo;
}
        
void Pila::push(Jugador* dato){

    Nodo* aux = new Nodo(dato);

    aux->setSiguiente(this->tope);

    this->setTope(aux); 
    this->tamanio += 1;
}
       
void* Pila::pop(){

    Nodo *aux = this->tope; 
    void *dato = aux->getDato();
  
    this->setTope(aux->getSiguiente()); 
    this->tamanio -= 1;
    
    delete aux; 
    return dato; 
}
        
void* Pila::top(){
    return this->tope->getDato();
}
       
bool Pila::vacia(){
    if(this->tamanio == 0){
        return true;
    }
    else{
        return false;
    }
}



