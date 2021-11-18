#include "Nodo.h"

Nodo::Nodo() {
	this->dato = NULL;
	this->siguiente = NULL;
}

void Nodo::setDato(Jugador* dato){
        this->dato = dato;
}
void Nodo::nodoDestruir(){
    Nodo* aux = this;
	while (aux->siguiente != NULL){
		aux->dato->destruirJugador();
		aux = aux->siguiente;
		delete this;
	}
	aux->dato->destruirJugador();
	delete aux;

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

