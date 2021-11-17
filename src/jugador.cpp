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

	char ficha;
	std::cout << "Ingrese su ficha" << std::endl;
	std::cin >> ficha;

	this->nombre = nombre;
	this->ficha = ficha;
	this->siguiente = NULL;
	this->cartas = new Carta[MAX_CARTAS];
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

Carta Jugador::getCartas(size_t pos){
	return this->cartas[pos];
}

Carta* Jugador::getCartasPuntero(){
	return this->cartas;
}

void Jugador::setJugadorSiguiente(Jugador* siguiente){
	this->siguiente = siguiente;
}

Jugador* Jugador::getJugadorSiguiente(){
	return this->siguiente;
}