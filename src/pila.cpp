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
    this->anterior = NULL;
}
    
void Pila::pilaDestruir(){

    
    while(this->tope->getSiguiente() != NULL){
    
        NodoPila* aux = this->tope;
        
        if(!this->vacia()){
            while(this->tope->getUltimo() != NULL){

                this->anterior = this->tope->getUltimo();
                delete (this->anterior);

            }
            delete(aux);
        }

        this->tope = NULL;
        this->tamanio = 0;    
        delete this;
    }

    this->anterior = NULL;
    this->tamanio = 0;
    delete this;
}

void Pila::setTope(NodoPila* ultimo){
    this->anterior = this->tope->getUltimo();
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



