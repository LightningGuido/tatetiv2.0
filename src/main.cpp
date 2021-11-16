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
	Tablero *tablero = new Tablero(dim, dim ,dim);
	Tablero *ultimo = new Tablero(dim, dim, dim);
	tablero->imprimirMapaCoordenado();

	std::cout << "Ingrese la cantidad de jugadores" << std::endl;
	size_t cantJugadores;
	std::cin >> cantJugadores;
	Cola *turnos = new Cola();
	Jugador *jugador = new Jugador[cantJugadores];

	for(size_t i = 0; i < cantJugadores; i++) {
		Nodo* actual = new Nodo(jugador + i);
		turnos->acolar(actual);
	}
		  //Verifica ganador
	while(tablero->hayGanador()) {
		//Colocan o mueven Fichas
		if(tablero->getCantidadFichas() < dim * cantJugadores) {
			fichasIniciales(turnos->frente(), tablero);

		} else {
			turno(tablero, turnos->frente());
		}

		//Muestram y juegan cartas
		tablero->imprimirTablero();
		for(size_t i = 0; i < MAX_CARTAS; i++){
			std::cout << i << ": ";
			turnos->frente()->getCartas(i).mostrarCarta();
		}
		std::cout << "Ingrese el TipoCarta que desea jugar o (-1) si no desea jugar ninguna: " << std::endl;
		int numero;
		cin >> numero;

		if(numero >= 0 && numero < MAX_CARTAS) {
			switch(turnos->frente()->getCartas(numero).getCarta()){
				case PerderTurno:
					std::cout <<"Juega carta PerderTurno" << std::endl;
					perderTurno(turnos);
					break;
				case BloquearFicha:
					std::cout <<"Juega carta BloquearFicha" << std::endl;
					bloquearFicha(tablero);
					break;
				case BloquearCasillero:
					std::cout <<"Juega carta BloquearCasillero" << std::endl;
					bloquearCasillero(tablero);
					break;
				case IrAtras:
					std::cout <<"Juega carta IrAtras" << std::endl;
					irAtras(tablero, ultimo);
					break;
				case PermutarLugar:
					std::cout <<"Juega carta PermutarLugar" << std::endl;
					permutarLugar(tablero);
					break;
				case TurnoDoble:
					std::cout <<"Juega carta TurnoDoble" << std::endl;
					turnoDoble(turnos);
					break;
			}
		} else {
			std::cout <<"No juega ninguna carta" << std::endl;
		}
		
		tablero->guardarEstado(ultimo);
		turnos->acolar(turnos->desacolar());
	}

	tablero->destruir();
	ultimo->destruir();
	turnos->ColaDestruir(); 
	return 0; 
}

