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

using namespace std;


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
	Tablero ultimo = Tablero(dim, dim, dim);

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
		fichasIniciales(turnos.frente(), &tablero);
		//carta:
		for(size_t i = 0; i < MAX_CARTAS; i++){
			turnos.frente()->getCarta(i).mostrarCarta();
		}
		std::cout << "Ingrese el TipoCarta que desea jugar o (-1) si no desea jugar ninguna: " << std::endl;
		int numero;
		cin >> numero;
		switch(numero){
			case -1:
				std::cout <<"No juega ninguna carta" << std::endl;
				break;
			case PerderTurno:
				std::cout <<"Juega carta PerderTurno" << std::endl;
				perderTurno(&turnos);
				break;
			case BloquearFicha:
				std::cout <<"Juega carta BloquearFicha" << std::endl;
				bloquearFicha(&tablero);
				break;
			case BloquearCasillero:
				std::cout <<"Juega carta BloquearCasillero" << std::endl;
				bloquearCasillero(&tablero);
				break;
			case IrAtras:
				std::cout <<"Juega carta IrAtras" << std::endl;
				irAtras(&tablero, &ultimo);
				break;
			case PermutarLugar:
				std::cout <<"Juega carta PermutarLugar" << std::endl;
				permutarLugar(&tablero);
				break;
			case TurnoDoble:
				std::cout <<"Juega carta TurnoDoble" << std::endl;
				turnoDoble(&turnos);
				break;
		}

		tablero.guardarEstado(&ultimo);
		//pasar turno
		turnos.acolar(turnos.desacolar());
		//verificasganador
		if(tablero.hayGanador()) {
			break;
		}
	}
	while(1) {
		turno(&tablero, turnos.frente());
		//carta
		tablero.guardarEstado(&ultimo);
		turnos.acolar(turnos.desacolar());
		if(tablero.hayGanador()) {
			break;
		}
	}

	return 0;
}

