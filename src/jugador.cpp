/*
 * jugador.cpp
 *
 *  Created on: Nov 9, 2021
 *      Author: guido
 */


#include "jugador.h"


Jugador::Jugador(char ficha, std::string nombre, unsigned int idTurno) {
	this->nombre = nombre;
	this->ficha = ficha;
	this->idTurno = idTurno;
}

void Jugador::setFicha(char ficha) {
	this->ficha = ficha;
}

char Jugador::getFicha() {
	return this->ficha;
}

std::string Jugador::getNombre() {
	return this->nombre;
}
