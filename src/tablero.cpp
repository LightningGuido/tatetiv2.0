/*
 * tablero.cpp
 *
 *  Created on: Nov 9, 2021
 *      Author: guido
 */

#include "tablero.h"

using namespace std;


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
				this->casillero[i][j][k].setEstado(Libre);
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

Casillero*** Tablero::getCasilleroPuntero() {
	return this->casillero;
}

Casillero Tablero::getCasillero(size_t x, size_t y, size_t z) {
	return this->casillero[x][y][z];
}

bool Tablero::hayGanador() {
	if(this->ganadorPlanoAncho()) {
		return true;
	}
	if(this->ganadorPlanoAnchoDiagonal1()) {
		return true;
	}
	if(this->ganadorPlanoAnchoDiagonal2()) {
		return true;
	}
	if(this->ganadorPlanoAlto()) {
		return true;
	}
	if(this->ganadorPlanoAltoDiagonal1()) {
		return true;
	}
	if(this->ganadorPlanoAltoDiagonal2()) {
		return true;
	}
	if(this->ganadorPlanoProf()) {
		return true;
	}
	if(this->ganadorPlanoProfDiagonal1()) {
		return true;
	}
	if(this->ganadorPlanoProfDiagonal2()) {
		return true;
	}
	if(this->ganadorDiagonales3D()) {
		return true;
	}
	return false;
}

bool Tablero::ganadorPlanoAncho() {

	unsigned int condicionVictoria;
	for(size_t x = 0; x < this->anchura; x++) {
		condicionVictoria = 0;
		//BUSCO GANADOR POR LA HORIZONTAL
		for(size_t y = 0; y < this->altura; y++) {
			for(size_t z = 0; z < this->profundidad - 1; z++) {
				if(this->casillero[x][y][z].getValor() == VACIO) break;
				if(this->casillero[x][y][z].getValor() == this->casillero[x][y][z+1].getValor())
					condicionVictoria++;
			}
			if(condicionVictoria == this->anchura - 1) return true;
			condicionVictoria = 0;
		}
		//BUSCO GANADOR POR LA VERTICAL
		for(size_t z = 0; z < this->profundidad; z++) {
			for(size_t y = 0; y < this->altura - 1; y++) {
				if(this->casillero[x][y][z].getValor() == VACIO) break;
				if(this->casillero[x][y][z].getValor() == this->casillero[x][y+1][z].getValor())
					condicionVictoria++;
			}
			if(condicionVictoria == this->altura - 1) return true;
			condicionVictoria = 0;
		}
	}
	return false;
}

bool Tablero::ganadorPlanoAnchoDiagonal1() {

	bool aux;
	for(size_t x = 0; x < this->anchura; x++) {
		aux = true;
		for(size_t y = 0, z = 0; y < this->altura - 1 && z < this->profundidad - 1; y++, z++) {
			if(this->casillero[x][y][z].getValor() == VACIO) {
				aux = false;
				break;
			}
			if(this->casillero[x][y][z].getValor() != this->casillero[x][y+1][z+1].getValor()) {
				aux = false;
				break;
			}
		}
		if(aux) return true;
	}
	return false;
}

bool Tablero::ganadorPlanoAnchoDiagonal2() {

	bool aux;
	for(size_t x = 0; x < this->anchura; x++) {
		aux = true;
		for(size_t y = 0, z = this->profundidad - 1; y < this->altura - 1 && z > 0; y++, z--) {
			if(this->casillero[x][y][z].getValor() == VACIO) {
				aux = false;
			}
			if(this->casillero[x][y][z].getValor() != this->casillero[x][y+1][z-1].getValor()) {
				aux = false;
			}
		}
		if(aux) return true;
	}
	return false;
}

bool Tablero::ganadorPlanoAlto() {

	unsigned int condicionVictoria;
	for(size_t y = 0; y < this->altura; y++) {
		condicionVictoria = 0;
		//BUSCO GANADOR POR LA HORIZONTAL
		for(size_t x = 0; x < this->anchura; x++) {
			for(size_t z = 0; z < this->profundidad - 1; z++) {
				if(this->casillero[x][y][z].getValor() == VACIO) break;
				if(this->casillero[x][y][z].getValor() == this->casillero[x][y][z+1].getValor())
					condicionVictoria++;
			}
			if(condicionVictoria == this->altura - 1) return true;
			condicionVictoria = 0;
		}
		//BUSCO GANADOR POR LA VERTICAL
		for(size_t z = 0; z < this->profundidad; z++) {
			for(size_t x = 0; x < this->anchura - 1; x++) {
				if(this->casillero[x][y][z].getValor() == VACIO) break;
				if(this->casillero[x][y][z].getValor() == this->casillero[x][y+1][z].getValor())
					condicionVictoria++;
			}
			if(condicionVictoria == this->altura - 1) return true;
			condicionVictoria = 0;
		}
	}
	return false;
}

bool Tablero::ganadorPlanoAltoDiagonal1() {

	bool aux;
	for(size_t y = 0; y < this->altura; y++) {
		aux = true;
		for(size_t x = 0, z = 0; y < this->anchura - 1 && z < this->profundidad - 1; x++, z++) {
			if(this->casillero[x][y][z].getValor() == VACIO) {
				aux = false;
				break;
			}
			if(this->casillero[x][y][z].getValor() != this->casillero[x+1][y][z+1].getValor()) {
				aux = false;
				break;
			}
		}
		if(aux) return true;
	}
	return false;
}

bool Tablero::ganadorPlanoAltoDiagonal2() {

	bool aux;
	for(size_t y = 0; y < this->altura; y++) {
		aux = true;
		for(size_t x = 0, z = this->profundidad - 1; x < this->anchura - 1 && z > 0; x++, z--) {
			if(this->casillero[x][y][z].getValor() == VACIO) {
				aux = false;
				break;
			}
			if(this->casillero[x][y][z].getValor() != this->casillero[x+1][y][z-1].getValor()) {
				aux = false;
				break;
			}
		}
		if(aux) return true;
	}
	return false;
}

bool Tablero::ganadorPlanoProf() {

	unsigned int condicionVictoria;
	for(size_t z = 0; z < this->profundidad; z++) {
		condicionVictoria = 0;
		//BUSCO GANADOR POR LA HORIZONTAL
		for(size_t y = 0; y < this->altura; y++) {
			for(size_t x = 0; z < this->anchura - 1; x++) {
				if(this->casillero[x][y][z].getValor() == VACIO) break;
				if(this->casillero[x][y][z].getValor() == this->casillero[x][y][z+1].getValor())
					condicionVictoria++;
			}
			if(condicionVictoria == this->profundidad - 1) return true;
			condicionVictoria = 0;
		}
		//BUSCO GANADOR POR LA VERTICAL
		for(size_t x = 0; z < this->anchura; x++) {
			for(size_t y = 0; y < this->altura - 1; y++) {
				if(this->casillero[x][y][z].getValor() == VACIO) break;
				if(this->casillero[x][y][z].getValor() == this->casillero[x][y+1][z].getValor())
					condicionVictoria++;
			}
			if(condicionVictoria == this->profundidad - 1) return true;
			condicionVictoria = 0;
		}
	}
	return false;
}

bool Tablero::ganadorPlanoProfDiagonal1() {

	bool aux;
	for(size_t z = 0; z < this->profundidad; z++) {
		aux = true;
		for(size_t y = 0, x = 0; y < this->altura - 1 && x < this->anchura - 1; y++, x++) {
			if(this->casillero[x][y][z].getValor() == VACIO) {
				aux = false;
				break;
			}
			if(this->casillero[x][y][z].getValor() != this->casillero[x+1][y+1][z].getValor()) {
				aux = false;
				break;
			}
		}
		if(aux) return true;
	}
	return false;
}

bool Tablero::ganadorPlanoProfDiagonal2() {

	bool aux;
	for(size_t z = 0; z < this->profundidad; z++) {
		aux = true;
		for(size_t y = 0, x = this->anchura - 1; y < this->altura - 1 && z > 0; y++, x--) {
			if(this->casillero[x][y][z].getValor() == VACIO) {
				aux = false;
				break;
			}
			if(this->casillero[x][y][z].getValor() != this->casillero[x-1][y+1][z].getValor()) {
				aux = false;
				break;
			}
		}
		if(aux) return true;
	}
	return false;
}

bool Tablero::ganadorDiagonales3D() {

	bool aux;
	aux = true;
	for(size_t x = 0, y = 0, z = 0; x < this->anchura - 1 && y < this->altura - 1 && z < this->profundidad - 1; x++, y++, z++) {
		if(this->casillero[x][y][z].getValor() == VACIO) {
			aux = false;
			break;
		}
		if(this->casillero[x][y][z].getValor() != this->casillero[x+1][y+1][z+1].getValor()) {
			aux = false;
			break;
		}
	}
	if(aux) return true;

	aux = true;
	for(size_t x = 0, y = this->altura - 1, z = 0; x < this->anchura - 1 && y > 0 && z < this->profundidad; x++, y--, z++) {
		if(this->casillero[x][y][z].getValor() == VACIO) {
			aux = false;
			break;
		}
		if(this->casillero[x][y][z].getValor() != this->casillero[x+1][y-1][z+1].getValor()) {
			aux = false;
			break;
		}
	}
	if(aux) return true;

	aux = true;
	for(size_t x = this->anchura - 1, y = 0, z = 0; x > 0 && y < this->altura - 1 && z < this->profundidad - 1; x--, y++, z++) {
		if(this->casillero[x][y][z].getValor() == VACIO) {
			aux = false;
			break;
		}
		if(this->casillero[x][y][z].getValor() != this->casillero[x-1][y+1][z+1].getValor()) {
			aux = false;
			break;
		}
	}
	if(aux) return true;

	for(size_t x = 0, y = 0, z = this->profundidad - 1; x < this->anchura && y < this->altura && z > 0; x++, y++, z--) {
		if(this->casillero[x][y][z].getValor() == VACIO) {
			aux = false;
			break;
		}
		if(this->casillero[x][y][z].getValor() != this->casillero[x+1][y+1][z-1].getValor()) {
			aux = false;
			break;
		}
	}
	if(aux) return true;

	return false;
}

void Tablero::guardarEstado(Tablero* aux){

	aux->altura = this->altura;
	aux->anchura = this->anchura;
	aux->profundidad = this->profundidad;
	aux->cantidadFichas = this->cantidadFichas;

	for(size_t i = 0; i < this->anchura; i++) {
		for(size_t j = 0; j < this->altura; j++) {
			for(size_t k = 0; k < this->profundidad; k++) {
				aux->casillero[i][j][k].setValor(this->casillero[i][j][k].getValor());
			}
		}
	}

}

void Tablero::imprimirTablero(){
	/* como es un cubo tiene 6 caras: */

		/*cara 1:
			x varia
			y varia
			z fija = 0*/
		std::cout << "CARA 1: "<< std::endl;
		for(size_t i = 0; i < this->anchura; i++){
			for(size_t j = 0; j < this->altura; j++){
				std::cout << "| " << this->casillero[i][j][0].getValor() << " |";
			}
			std::cout << std::endl;
		}
		/*cara 2:
			x fijo = tablero->anchura
			y varia
			z varia*/
		std::cout << "CARA 2: "<< std::endl;
		for(size_t i = 0; i < this->profundidad; i++){
			for(size_t j = 0; j < this->altura; j++){
				std::cout << "| " << this->casillero[this->anchura][j][i].getValor() << " |";
			}
			std::cout << std::endl;
		}
		/*cara 3: 
			x varia
			y fijo = tablero->altura
			z */
		std::cout << "CARA 3: "<< std::endl;
		for(size_t i = 0; i < this->profundidad; i++){
			for(size_t j = 0; j < this->anchura; j++){
				std::cout << "| " << this->casillero[j][this->altura][i].getValor() << " |";
			}
			std::cout << std::endl;
		}
		/*cara 4:
			x fijo = 0
			y varia
			z varia*/
		std::cout << "CARA 4: "<< std::endl;
		for(size_t i = 0; i < this->profundidad; i++){
			for(size_t j = 0; j < this->altura; j++){
				std::cout << "| " << this->casillero[0][j][i].getValor() << " |";
			}
			std::cout << std::endl;
		}
		/*cara 5:
			x varia
			y varia
			z fijo = tablero->profundidad */
		std::cout << "CARA 5: "<< std::endl;
		for(size_t i = 0; i < this->anchura; i++){
			for(size_t j = 0; j < this->altura; j++){
				std::cout << "| " << this->casillero[i][j][this->profundidad].getValor() << " |";
			}
			std::cout << std::endl;
		}
		/*cara 6:
			x varia
			y fijo = 0
			z varia	*/
		std::cout << "CARA 6: "<< std::endl;
		for(size_t i = 0; i < this->profundidad; i++){
			for(size_t j = 0; j < this->anchura; j++){
				std::cout << "| " << this->casillero[j][0][i].getValor() << " |";
			}
			std::cout << std::endl;
		}
		
}

void Tablero::imprimirMapaCoordenado(){
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "CARA 1: "<< std::endl;
		for(size_t i = 0; i < this->anchura; i++){
			for(size_t j = 0; j < this->altura; j++){
				std::cout << "|x = " << i << "; y = " << j << "; z = 0 |";
			}
			std::cout << std::endl;
		}
	
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "CARA 2: "<< std::endl;
		for(size_t i = 0; i < this->profundidad; i++){
			for(size_t j = 0; j < this->altura; j++){
				std::cout << "|x = " << this->anchura << "; y = " << j << "; z = " << i << " |";
			}
			std::cout << std::endl;
		}
	
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "CARA 3: "<< std::endl;
		for(size_t i = 0; i < this->profundidad; i++){
			for(size_t j = 0; j < this->anchura; j++){
				std::cout << "|x = " << j << "; y = " << this->altura << "; z = " << i << " |";
			}
			std::cout << std::endl;
		}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "CARA 4: "<< std::endl;
		for(size_t i = 0; i < this->profundidad; i++){
			for(size_t j = 0; j < this->altura; j++){
				std::cout << "|x = 0; y = " << j << "; z = " << i << " |";
			}
			std::cout << std::endl;
		}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "CARA 5: "<< std::endl;
		for(size_t i = 0; i < this->anchura; i++){
			for(size_t j = 0; j < this->altura; j++){
				std::cout << "|x = " << i << "; y = " << j << "; z = " << this->profundidad << " |";
			}
			std::cout << std::endl;
		}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "CARA 6: "<< std::endl;
		for(size_t i = 0; i < this->profundidad; i++){
			for(size_t j = 0; j < this->anchura; j++){
				std::cout << "|x =  " << j << "; y = 0; z = " << i << " |";
			}
			std::cout << std::endl;
		}


}

void Tablero::destruir(){
	for(size_t i = 0; i < this->anchura; i++) {
		for(size_t j = 0; j < this->altura; j++) {
			delete [] this->casillero[i][j];
		}
	}
	for(size_t i = 0; i < this->anchura; i++) {
		delete [] this->casillero[i];	
	}
	delete [] this->casillero;
	delete this;
}
