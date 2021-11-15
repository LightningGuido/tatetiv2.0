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
	size_t jugadores;
	std::cin >> jugadores;
	Cola *turnos = new Cola();

	for(size_t i = 0; i < jugadores; i++) {
		std::cout << "Jugador " << i + 1 << std::endl;
		Jugador *jugador = new Jugador(i + 1);
		turnos->acolar(jugador);
	}
		  //Verifica ganador
	while(tablero->hayGanador()) {
		//Colocan o mueven Fichas
		if(tablero->getCantidadFichas() < dim * jugadores) {
			fichasIniciales(turnos->frente(), tablero);
		} else {
			turno(tablero, turnos->frente());
		}

		//Muestram y juegan cartas
		for(size_t i = 0; i < MAX_CARTAS; i++){
			std::cout << i << ": ";
			turnos->frente()->getCartas(i).mostrarCarta();
		}
		std::cout << "Ingrese el TipoCarta que desea jugar o (-1) si no desea jugar ninguna: " << std::endl;
		int numero;
		cin >> numero;

		if(numero <= -1 || numero > MAX_CARTAS) {
			switch(turnos->frente()->getCartas(numero).getCarta()){
				case -1:
					std::cout << "No juega ninguna carta" << std::endl;
					break;
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
/*
	//COLOCO FICHAS
	while(tablero->getCantidadFichas() < dim * jugadores) {
		fichasIniciales(turnos->frente(), tablero);
		//carta:
		for(size_t i = 0; i < MAX_CARTAS; i++){
			std::cout << i << ": ";
			turnos->frente()->getCartas(i).mostrarCarta();
		}
		std::cout << "Ingrese el TipoCarta que desea jugar o (-1) si no desea jugar ninguna: " << std::endl;
		int numero;
		cin >> numero;

		if(numero <= -1 || numero > MAX_CARTAS) {
			switch(turnos->frente()->getCartas(numero).getCarta()){
				case -1:
					std::cout <<"No juega ninguna carta" << std::endl;
					break;
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
		//pasar turno
		turnos->acolar(turnos->desacolar());
		//verificasganador
		if(tablero->hayGanador()) {
			break;
		}
	}
	while(1) {
		turno(tablero, turnos->frente());
		//carta
		for(size_t i = 0; i < MAX_CARTAS; i++){
			std::cout << i << ": ";
			turnos->frente()->getCartas(i).mostrarCarta();
		}
		std::cout << "Ingrese el TipoCarta que desea jugar o (-1) si no desea jugar ninguna: " << std::endl;
		int numero;
		cin >> numero;

		if(numero <= -1 || numero > MAX_CARTAS) {
			switch(turnos->frente()->getCartas(numero).getCarta()){
				case -1:
					std::cout <<"No juega ninguna carta" << std::endl;
					break;
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
		if(tablero->hayGanador()) {
			break;
		}
	}
*/
	tablero->destruir();
	ultimo->destruir();
	//turnos->ColaDestruir(destruirDato());  ???
	return 0; 
}

