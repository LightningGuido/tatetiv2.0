#include "Nodo.h"

Nodo::Nodo() {
	this->dato = NULL;
	this->siguiente = NULL;
}

void Nodo::setDato(Jugador* dato){
        this->dato = dato;
}
Nodo::~Nodo(){
	//delete this->dato;
}
Jugador* Nodo::getDato(){
        return this->dato;
}
Nodo* Nodo::getSiguiente(){
        return this->siguiente; 
}

void Nodo::setSiguiente(Nodo* nodo){
        this->siguiente = nodo;
}

