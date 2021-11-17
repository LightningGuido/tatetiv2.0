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
    
    while(this->anterior != NULL){
        
        Tablero* aux = this->tope;

        this->tope = this->anterior;
        delete (aux);
        
    }
    this->anterior = NULL;
    this->tamanio = 0;
    delete this;
}

void Pila::setTope(Tablero* ultimo){
    this->tope = ultimo;
}
        
void Pila::push(Tablero* dato){

    delete(this->anterior); //solo se guardan dos tableros

    this->anterior = this->tope;
    this->tope = dato;

    //this->tamanio += 1;
}
       
Tablero* Pila::pop(){

    
    Tablero* dato = this->tope;
  
    this->setTope(this->anterior); 
    this->tamanio -= 1;
    
    return dato; 
}
        
Tablero* Pila::top(){
    
    return this->tope;
}
       
bool Pila::vacia(){
    if(this->tamanio == 0){
        return true;
    }
    else{
        return false;
    }
}



