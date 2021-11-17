/*
 * casillero.cpp
 *
 *  Created on: Nov 9, 2021
 *      Author: guido
 */

#include "casillero.h"

/*Casillero::Casillero(char valor) {
	this->valor = valor;
	this->estado = Libre;
}*/

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

