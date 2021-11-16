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
        
        NodoPila* aux = this->tope;

        if(destruirDato){
            destruirDato(aux->getUltimo());
        }
        
        this->tope = aux->getSiguiente();
    
        delete aux;
    }

    delete this;
}

void Pila::setTope(NodoPila* nodo){
    this->tope = nodo;
}
        
void Pila::push(Tablero* dato){

    NodoPila* aux = new NodoPila(dato);

    aux->setSiguiente(this->tope);

    this->setTope(aux); 
    this->tamanio += 1;
}
       
Tablero* Pila::pop(){

    NodoPila *aux = this->tope; 
    Tablero* dato = aux->getUltimo();
  
    this->setTope(aux->getSiguiente()); 
    this->tamanio -= 1;
    
    delete aux; 
    return dato; 
}
        
Tablero* Pila::top(){
    NodoPila* aux = this->tope->getSiguiente();
    return aux->getUltimo();
}
       
bool Pila::vacia(){
    if(this->tamanio == 0){
        return true;
    }
    else{
        return false;
    }
}



