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

Pila::~Pila(){

	NodoPila* aux = NULL;

     while(this->tope != NULL){

        aux = this->tope;
        this->tope = aux->getSiguiente();
    
        delete(aux);
         
      }

}

void Pila::setTope(NodoPila* ultimo){ //no entiendo la diferencia entre setTope y push
    ultimo->setSiguiente(this->tope);
    this->tope = ultimo;
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



