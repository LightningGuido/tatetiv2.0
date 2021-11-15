/*
 * main.cpp
 *
 *  Created on: Nov 9, 2021
 *      Author: guido
 */

#include "tablero.h"
#include "jugador.h"
#include "pila.h"
#include "cola.h"
#include "juego.h"

int main() {
	/* PRIMERO: Se pregunta la cantidad de jugadores y dimension del tablero
	 *
	 * SEGUNDO: Se crea el tablero y jugadores
	 *
	 * TERCERO: Se inicia el juego
	 * 			Los jugadores se acomodan en una cola, que seria el orden
	 * 			de los turnos
	 *
	 */

	//INICIALIZO EL JUEGO
	std::cout << "Bienvenido al TaTeTi v2.0" << std::endl;
	std::cout << "Ingrese la dimension 3D de su cubo" << std::endl;
	size_t dim;
	std::cin >> dim;
	Tablero tablero = Tablero(dim, dim ,dim);

	std::cout << "Ingrese la cantidad de jugadores" << std::endl;
	size_t jugadores;
	std::cin >> jugadores;
	Cola turnos = Cola();

	for(size_t i = 0; i < jugadores; i++) {
		std::cout << "Jugador " << i + 1 << std::endl;
		Jugador jugador = Jugador(i + 1);
		turnos.acolar(&jugador);
	}

	//COLOCO FICHAS
	while(tablero.getCantidadFichas() < dim * jugadores) {

	}
	while(1) {

	}

	return 0;
}

