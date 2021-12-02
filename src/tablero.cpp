/*
 * tablero.cpp
 *
 *  Created on: Nov 9, 2021
 *      Author: guido
 */

#include "tablero.h"

using namespace std;


void Tablero::setAnchura(int ancho) {
	this->anchura = ancho;
}

void Tablero::setAltura(int alto) {
	this->altura = alto;
}

void Tablero::setProfundidad(int profundo) {
	this->profundidad = profundo;
}

void Tablero::setCantidadFichas(int n) {
	this->cantidadFichas = 0;
}

Tablero::Tablero(int ancho, int alto, int profundo) {

	this->casillero = new Casillero***[ancho];
	if(this->casillero == NULL) {

	}
	for(int i = 0; i < ancho; i++) {
			this->casillero[i] = new Casillero**[alto];
			for(int j = 0; j < alto; j++) {
				this->casillero[i][j] = new Casillero*[profundo];
			}
	}

	for(int i = 0; i < ancho; i++) {
		for(int j = 0; j < alto; j++) {
			for(int k = 0; k < profundo; k++) {
				this->casillero[i][j][k] = new Casillero;
			}
		}
	}

	this->cantidadFichas = 0;
	setAnchura(ancho);
	setAltura(alto);
	setProfundidad(profundo);

}

unsigned int Tablero::getCantidadFichas() {
	return this->cantidadFichas;
}

int Tablero::getAnchura() {
	return this->anchura;
}

int Tablero::getAltura() {
	return this->altura;
}

int Tablero::getProfundidad() {
	return this->profundidad;
}


Casillero* Tablero::getCasillero(int x, int y, int z) {
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

	int condicionVictoria;
	for(int x = 0; x < this->anchura; x++) {
		condicionVictoria = 0;
		//BUSCO GANADOR POR LA HORIZONTAL
		for(int y = 0; y < this->altura; y++) {
			for(int z = 0; z < this->profundidad - 1; z++) {
				if(this->casillero[x][y][z]->getValor() == VACIO) break;
				if(this->casillero[x][y][z]->getValor() == this->casillero[x][y][z+1]->getValor())
					condicionVictoria++;
			}
			if(condicionVictoria == this->anchura - 1) {
				return true;
			}
			condicionVictoria = 0;
		}
		//BUSCO GANADOR POR LA VERTICAL
		for(int z = 0; z < this->profundidad; z++) {
			for(int y = 0; y < this->altura - 1; y++) {
				if(this->casillero[x][y][z]->getValor() == VACIO) {
					break;
				}
				if(this->casillero[x][y][z]->getValor() == this->casillero[x][y+1][z]->getValor())
					condicionVictoria++;
			}
			if(condicionVictoria == this->altura - 1) {
				return true;
			}
			condicionVictoria = 0;
		}
	}
	return false;
}

bool Tablero::ganadorPlanoAnchoDiagonal1() {

	bool aux;
	for(int x = 0; x < this->anchura; x++) {
		aux = true;
		for(int y = 0, z = 0; (y < this->altura - 1) && (z < this->profundidad - 1); y++, z++) {
			if(this->casillero[x][y][z]->getValor() == VACIO) {
				aux = false;
				break;
			}
			if(this->casillero[x][y][z]->getValor() != this->casillero[x][y+1][z+1]->getValor()) {
				aux = false;
				break;
			}
		}
		if(aux) {
			return true;
		}
	}
	return false;
}

bool Tablero::ganadorPlanoAnchoDiagonal2() {

	bool aux;
	for(int x = 0; x < this->anchura; x++) {
		aux = true;
		for(int y = 0, z = this->profundidad - 1; y < this->altura - 1 && z > 0; y++, z--) {
			if(this->casillero[x][y][z]->getValor() == VACIO) {
				aux = false;
			}
			if(this->casillero[x][y][z]->getValor() != this->casillero[x][y+1][z-1]->getValor()) {
				aux = false;
			}
		}
		if(aux) {
			return true;
		}
	}
	return false;
}

bool Tablero::ganadorPlanoAlto() {

	int condicionVictoria;
	for(int y = 0; y < this->altura; y++) {
		condicionVictoria = 0;
		//BUSCO GANADOR POR LA HORIZONTAL
		for(int x = 0; x < this->anchura; x++) {
			for(int z = 0; z < this->profundidad - 1; z++) {
				if(this->casillero[x][y][z]->getValor() == VACIO) break;
				if(this->casillero[x][y][z]->getValor() == this->casillero[x][y][z+1]->getValor())
					condicionVictoria++;
			}
			if(condicionVictoria == this->altura - 1) {
				return true;
			}
			condicionVictoria = 0;
		}
		//BUSCO GANADOR POR LA VERTICAL
		for(int z = 0; z < this->profundidad; z++) {
			for(int x = 0; x < this->anchura - 1; x++) {
				if(this->casillero[x][y][z]->getValor() == VACIO) break;
				if(this->casillero[x][y][z]->getValor() == this->casillero[x + 1][y][z]->getValor())
					condicionVictoria++;
			}
			if(condicionVictoria == this->altura - 1) {
				return true;
			}
			condicionVictoria = 0;
		}
	}
	return false;
}

bool Tablero::ganadorPlanoAltoDiagonal1() {

	bool aux;
	for(int y = 0; y < this->altura; y++) {
		aux = true;
		for(int x = 0, z = 0; (x < this->anchura - 1) && (z < this->profundidad - 1); x++, z++) {
			if(this->casillero[x][y][z]->getValor() == VACIO) {
				aux = false;
				break;
			}
			if(this->casillero[x][y][z]->getValor() != this->casillero[x+1][y][z+1]->getValor()) {
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
	for(int y = 0; y < this->altura; y++) {
		aux = true;
		for(int x = 0, z = this->profundidad - 1; x < this->anchura - 1 && z > 0; x++, z--) {
			if(this->casillero[x][y][z]->getValor() == VACIO) {
				aux = false;
				break;
			}
			if(this->casillero[x][y][z]->getValor() != this->casillero[x+1][y][z-1]->getValor()) {
				aux = false;
				break;
			}
		}
		if(aux) {
			return true;
		}
	}
	return false;
}

bool Tablero::ganadorPlanoProf() {

	int condicionVictoria;
	for(int z = 0; z < this->profundidad - 1; z++) {
		condicionVictoria = 0;
		//BUSCO GANADOR POR LA HORIZONTAL
		for(int y = 0; y < this->altura; y++) {
			for(int x = 0; x < this->anchura; x++) {
				if(this->casillero[x][y][z]->getValor() == VACIO) {
					break;
				}
				if(this->casillero[x][y][z]->getValor() == this->casillero[x][y][z+1]->getValor()) //aca valgrind tira error
					condicionVictoria++;
			}
			if(condicionVictoria == this->profundidad - 1) {
				return true;
			}
			condicionVictoria = 0;
		}
		//BUSCO GANADOR POR LA VERTICAL
		for(int x = 0; x < this->anchura; x++) {
			for(int y = 0; y < this->altura - 1; y++) {
				if(this->casillero[x][y][z]->getValor() == VACIO) {
					break;
				}
				if(this->casillero[x][y][z]->getValor() == this->casillero[x][y+1][z]->getValor())
					condicionVictoria++;
			}
			if(condicionVictoria == this->profundidad - 1) {
				return true;
			}
			condicionVictoria = 0;
		}
	}
	return false;
}

bool Tablero::ganadorPlanoProfDiagonal1() {

	bool aux;
	for(int z = 0; z < this->profundidad; z++) {
		aux = true;
		for(int y = 0, x = 0; y < this->altura - 1 && x < this->anchura - 1; y++, x++) {
			if(this->casillero[x][y][z]->getValor() == VACIO) {
				aux = false;
				break;
			}
			if(this->casillero[x][y][z]->getValor() != this->casillero[x+1][y+1][z]->getValor()) {
				aux = false;
				break;
			}
		}
		if(aux) {
			return true;
		}
	}
	return false;
}

bool Tablero::ganadorPlanoProfDiagonal2() {

	bool aux;
	for(int z = 0; z < this->profundidad; z++) {
		aux = true;
		for(int y = 0, x = this->anchura - 1; y < this->altura - 1 && x > 0; y++, x--) {
			if(this->casillero[x][y][z]->getValor() == VACIO) {
				aux = false;
				break;
			}
			if(this->casillero[x][y][z]->getValor() != this->casillero[x-1][y+1][z]->getValor()) {
				aux = false;
				break;
			}
		}
		if(aux) {
			return true;
		}
	}
	return false;
}

bool Tablero::ganadorDiagonales3D() {

	bool aux;
	aux = true;
	for(int x = 0, y = 0, z = 0; x < this->anchura - 1 && y < this->altura - 1 && z < this->profundidad - 1; x++, y++, z++) {
		if(this->casillero[x][y][z]->getValor() == VACIO) {
			aux = false;
			break;
		}
		if(this->casillero[x][y][z]->getValor() != this->casillero[x+1][y+1][z+1]->getValor()) {
			aux = false;
			break;
		}
	}
	if(aux) return true;

	aux = true;
	for(int x = 0, y = this->altura - 1, z = 0; x < this->anchura - 1 && y > 0 && z < this->profundidad - 1; x++, y--, z++) {
		if(this->casillero[x][y][z]->getValor() == VACIO) {
			aux = false;
			break;
		}
		if(this->casillero[x][y][z]->getValor() != this->casillero[x+1][y-1][z+1]->getValor()) {
			aux = false;
			break;
		}
	}
	if(aux) {
		return true;
	}

	aux = true;
	for(int x = this->anchura - 1, y = 0, z = 0; x > 0 && y < this->altura - 1 && z < this->profundidad - 1; x--, y++, z++) {
		if(this->casillero[x][y][z]->getValor() == VACIO) {
			aux = false;
			break;
		}
		if(this->casillero[x][y][z]->getValor() != this->casillero[x-1][y+1][z+1]->getValor()) {
			aux = false;
			break;
		}
	}
	if(aux) {
		return true;
	}

	for(int x = 0, y = 0, z = this->profundidad - 1; x < this->anchura - 1 && y < this->altura - 1 && z > 0; x++, y++, z--) {
		if(this->casillero[x][y][z]->getValor() == VACIO) {
			aux = false;
			break;
		}
		if(this->casillero[x][y][z]->getValor() != this->casillero[x+1][y+1][z-1]->getValor()) {
			aux = false;
			break;
		}
	}
	if(aux) {
		return true;
	}

	return false;
}

Tablero* Tablero::guardarEstado(){

	Tablero* aux = new Tablero(this->anchura, this->altura, this->profundidad);

	
	aux->cantidadFichas = this->cantidadFichas;

	for(int i = 0; i < this->anchura; i++) {
		for(int j = 0; j < this->altura; j++) {
			for(int k = 0; k < this->profundidad; k++) {
				aux->getCasillero(i,j,k)->setValor(this->casillero[i][j][k]->getValor());
				aux->getCasillero(i,j,k)->setEstado(this->casillero[i][j][k]->getEstado());
			}
		}
	}
	return aux;

}

void Tablero::imprimirAncho() {

	for(int x = 0; x < this->anchura; x++) {
		std::cout << "CARA (ANCHO): " << x + 1 << std::endl;
		for(int y = 0; y < this->altura; y++) {
			for(int z = 0; z < this->profundidad; z++) {
				std::cout << this->getCasillero(x, y, z)->getValor();
				if(z != this->profundidad -1) std::cout << '|';
			}
			std::cout << endl;
			if(y != this->altura - 1) {
				for(int i = 0; i < (2 * this->profundidad - 1); i++) {
					std::cout << '-';
				}
			}
			std::cout << endl;
		}
	}
}

void Tablero::imprimirAnchoCoordenado() {

	for(int x = 0; x < this->anchura; x++) {
		std::cout << "CARA (ANCHO): " << x + 1 << std::endl;
		for(int y = 0; y < this->altura; y++) {
			for(int z = 0; z < this->profundidad; z++) {
				std::cout << "[x = " << x << "][y = " << y << "][z = " << z << "] ";
			}
			std::cout << endl;
		}
	}
}

void Tablero::imprimirAlto() {

	for(int y = 0; y < this->altura; y++) {
		std::cout << "CARA (ALTO): " << y + this->anchura + 1 << std::endl;
		for(int x = 0; x < this->anchura; x++) {
			for(int z = 0; z < this->profundidad; z++) {
				std::cout << this->getCasillero(x, y, z)->getValor();
				if(z != this->profundidad -1) std::cout << '|';
			}
			std::cout << endl;
			if(x != this->anchura - 1) {
				for(int i = 0; i < (2 * this->profundidad - 1); i++) {
					std::cout << '-';
				}
			}
			std::cout << endl;
		}
	}
}

void Tablero::imprimirAltoCoordenado() {

	for(int y = 0; y < this->altura; y++) {
		std::cout << "CARA (ALTO): " << y + this->anchura + 1 << std::endl;
		for(int x = 0; x < this->anchura; x++) {
			for(int z = 0; z < this->profundidad; z++) {
				std::cout << "[x = " << x << "][y = " << y << "][z = " << z << "] ";
			}
			std::cout << endl;
		}
	}
}

void Tablero::imprimirProf() {

	for(int z = 0; z < this->profundidad; z++) {
		std::cout << "CARA (PROF): " << z + this->altura + this->anchura + 1 << std::endl;
		for(int y = 0; y < this->altura; y++) {
			for(int x = 0; x < this->anchura; x++) {
				std::cout << this->getCasillero(x, y, z)->getValor();
				if(x != this->anchura -1) std::cout << '|';
			}
			std::cout << endl;
			if(y != this->altura - 1) {
				for(int i = 0; i < (2 * this->anchura - 1); i++) {
					std::cout << '-';
				}
			}
			std::cout << endl;
		}
	}
}

void Tablero::imprimirProfCoordenado() {

	for(int z = 0; z < this->profundidad; z++) {
		std::cout << "CARA (PROF): " << z + this->altura + this->anchura + 1 << std::endl;
		for(int y = 0; y < this->altura; y++) {
			for(int x = 0; x < this->anchura; x++) {
				std::cout << "[x = " << x << "][y = " << y << "][z = " << z << "] ";
			}
			std::cout << endl;
		}
	}
}

void Tablero::imprimirTablero(){

	this->imprimirAncho();
	this->imprimirAlto();
	this->imprimirProf();


}

void Tablero::imprimirMapaCoordenado(){

	this->imprimirAnchoCoordenado();
	this->imprimirAltoCoordenado();
	this->imprimirProfCoordenado();

}

Tablero::~Tablero(){
	for(int i = 0; i < this->anchura; i++) {
		for(int j = 0; j < this->altura; j++) {
			for(int k = 0; k < this->profundidad; k++) {
				delete  this->casillero[i][j][k];
			}
			delete [] this->casillero[i][j];
		}
		delete [] this->casillero[i];
	}

	delete[] this->casillero;

}
