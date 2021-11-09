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

void inicializarTablero(Tablero *tablero) {


}

Tablero::Tablero(size_t ancho, size_t alto, size_t profundo) {

	this->casillero = new Casillero**[ancho];
	if(this->casillero == NULL) {
		//throw
	}
	for(size_t i = 0; i < ancho; i++) {
			this->casillero[i] = new Casillero*[alto];
			for(size_t j = 0; j < alto; j++) {
				this->casillero[i][j];
			}
	}

	for(size_t i = 0; i < ancho; i++) {
		for(size_t j = 0; j < alto; j++) {
			for(size_t k = 0; k < profundo; k++) {
				//ESTO HAY QUE CORREGIRLO, PERO AHORA ME DA PAJA PENSARLO
				this->casillero[i][j][k].valor = VACIO;
			}
		}
	}

	this->cantidadFichas = 0;
	setAnchura(ancho);
	setAltura(alto);
	setProfundidad(profundo);

}


