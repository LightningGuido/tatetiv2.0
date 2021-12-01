/*
 * cartas.cpp
 *
 *  Created on: Nov 9, 2021
 *      Author: guido
 */

#include "cartas.h"


Carta::Carta() {
	this->carta = TipoCarta(rand() % 6);
	this->estado = Disponible;
}
Carta::~Carta(){

}

TipoCarta Carta::getTipoCarta() {
	return this->carta;
}

void Carta::mostrarCarta() {
	switch(this->carta) {
	case 0:
		if(this->estado == Disponible){
			std::cout << "Perder turno" << std::endl;
		}
		break;
	case 1:
		if(this->estado == Disponible){
			std::cout << "Bloquear Ficha" << std::endl;
		}
		break;
	case 2:
		if(this->estado == Disponible){
			std::cout << "Bloquear Casillero" << std::endl;
		}
		break;
	case 3:
		if(this->estado == Disponible){
			std::cout << "Ir Atras" << std::endl;
		}
		break;
	case 4:
		if(this->estado == Disponible){
			std::cout << "Permutar Lugar" << std::endl;
		}
		break;
	case 5:
		if(this->estado == Disponible){
			std::cout << "Turno Doble" << std::endl;
		}
		break;
	}
}

void Carta::setEstado(EstadoCarta estado){
	this->estado = estado;
}

EstadoCarta Carta::getEstado(){
	return this->estado;
}
