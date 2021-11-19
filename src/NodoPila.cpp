#include "NodoPila.h"

NodoPila::NodoPila(Tablero* dato){
    this->ultimo = dato;
    this->siguiente = NULL;
}

NodoPila::~NodoPila(){

    delete this->ultimo;

}
Tablero* NodoPila::getUltimo(){
    return this->ultimo;
}
NodoPila* NodoPila::getSiguiente(){
    return this->siguiente;
}
void NodoPila::setSiguiente(NodoPila* nodo){
    this->siguiente = nodo;
}
    
