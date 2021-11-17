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
    
void Pila::pilaDestruir(){

    if(!this->vacia()){
        while(this->tope->getSiguiente() != NULL){
    
        NodoPila* aux = this->tope->getSiguiente();
        this->tope->setSiguiente(aux->getSiguiente());
    
        delete(aux->getUltimo());
        delete(aux);
         
        }
        delete(this->tope); 
    }

    this->tamanio = 0;    
    delete this;

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



