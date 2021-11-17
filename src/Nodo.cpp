#include "Nodo.h"


Nodo::Nodo(Jugador* dato){
        this->dato = dato;
        this->siguiente = NULL;
}
void Nodo::nodoDestruir(){
        delete this->siguiente;
        delete this->dato;
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

