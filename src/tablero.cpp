/*
 * tablero.cpp
 *
 *  Created on: Nov 9, 2021
 *      Author: guido
 */

#include "tablero.h"

using namespace std;
const char VACIO = ' ';

void Tablero::setAnchura(size_t ancho) {
	this->anchura = ancho;
}

void Tablero::setAltura(size_t alto) {
	this->altura = alto;
}

void Tablero::setProfundidad(size_t profundo) {
	this->profundidad = profundo;
}

void Tablero::setCantidadFichas(size_t n) {
	this->cantidadFichas = 0;
}

Tablero::Tablero(size_t ancho, size_t alto, size_t profundo) {

	this->casillero = new Casillero**[ancho];
	if(this->casillero == NULL) {
		//throw
	}
	for(size_t i = 0; i < ancho; i++) {
			this->casillero[i] = new Casillero*[alto];
			for(size_t j = 0; j < alto; j++) {
				this->casillero[i][j] = new Casillero[profundo];
			}
	}

	for(size_t i = 0; i < ancho; i++) {
		for(size_t j = 0; j < alto; j++) {
			for(size_t k = 0; k < profundo; k++) {
				this->casillero[i][j][k].setValor(VACIO);
			}
		}
	}

	this->setCantidadFichas(0);
	this->setAnchura(ancho);
	this->setAltura(alto);
	this->setProfundidad(profundo);
}

unsigned int Tablero::getCantidadFichas() {
	return this->cantidadFichas;
}

size_t Tablero::getAnchura() {
	return this->anchura;
}

size_t Tablero::getAltura() {
	return this->altura;
}

size_t Tablero::getProfundidad() {
	return this->profundidad;
}
