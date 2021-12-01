/*
 * casillero.cpp
 *
 *  Created on: Nov 9, 2021
 *      Author: guido
 */

#include "casillero.h"

Casillero::Casillero(){
	this->valor = VACIO;
	this->estado = Libre;
}

void Casillero::setValor(char valor) {
	this->valor = valor;
}

void Casillero::setEstado(StatusCasillero estado) {
	this->estado = estado;
}

char Casillero::getValor(){
	return this->valor;
}

StatusCasillero Casillero::getEstado() {
	return this->estado;
}

bool Casillero::estaVacio(){
	if(this->valor == VACIO){
		return true;
	}else{
		return false;
	}
}

bool Casillero::estaLibre(){
	if(this->estado == Libre){
		return true;
	}else{
		return false;
	}
}

Casillero::~Casillero(){

}
