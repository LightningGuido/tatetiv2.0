/*
 * jugador.cpp
 *
 *  Created on: Nov 9, 2021
 *      Author: guido
 */


#include "jugador.h"


Jugador::Jugador() {
	std::string nombre;
	std::cout << "Ingrese su nombre" << std::endl;
	std::cin >> nombre;

	std::string ficha;
	std::cout << "Ingrese su ficha" << std::endl;
	std::cin >> ficha;


	this->nombre = nombre;
	this->ficha = ficha[0];
	this->cartas = new Carta*[MAX_CARTAS];
	for (int i = 0; i< MAX_CARTAS; i++){
		this->cartas[i] = new Carta();
	}
}

Jugador::~Jugador(){
	for (int i = 0; i< MAX_CARTAS; i++){
		delete this->cartas[i];
	}
	delete[] this->cartas;

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

Carta* Jugador::getCartas(int pos){
	return this->cartas[pos];
}



