/*
 * cartas.cpp
 *
 *  Created on: Nov 9, 2021
 *      Author: guido
 */

#include "cartas.h"


Carta::Carta() {
	this->carta = TipoCarta(rand() % 6);
}

TipoCarta Carta::getCarta() {
	return this->carta;
}

void Carta::mostrarCarta() {
	switch(this->carta) {
	case 0:
		std::cout << "Perder turno" << std::endl;
		break;
	case 1:
		std::cout << "Bloquear Ficha" << std::endl;
		break;
	case 2:
		std::cout << "Bloquear Casillero" << std::endl;
		break;
	case 3:
		std::cout << "Ir Atras" << std::endl;
		break;
	case 4:
		std::cout << "Permutar Lugar" << std::endl;
		break;
	case 5:
		std::cout << "Turno Doble" << std::endl;
		break;
	}
}
