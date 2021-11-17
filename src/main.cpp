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

	std::cout << "Bienvenido al TaTeTi v2.0" << std::endl;
	std::cout << "Ingrese la dimension 3D de su cubo" << std::endl;
	size_t dim;
	std::cin >> dim;
	Tablero *tablero = new Tablero(dim, dim ,dim);
	Pila* ultimosTableros = new Pila;
	tablero->imprimirMapaCoordenado();
	tablero->imprimirTablero();

	std::cout << "Ingrese la cantidad de jugadores" << std::endl;
	size_t cantJugadores;
	std::cin >> cantJugadores;
	Cola *turnos = new Cola();
	Nodo *nodo = new Nodo();
	Jugador **jugadores = new Jugador*[cantJugadores];

	for(size_t i = 0; i < cantJugadores; i++) {
		jugadores[i] = new Jugador();
		nodo[i].setDato(jugadores[i]);
		turnos->acolar(&nodo[i]);
	}

	for(size_t i = 0; i < cantJugadores; i++) {
		cout << turnos->frente()->getNombre() <<endl;
		turnos->acolar(turnos->desacolar());
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
		tablero->imprimirTablero(); //aca xplota
		for(size_t i = 0; i < MAX_CARTAS; i++){
			std::cout << i << ": ";
			turnos->frente()->getCartas(i).mostrarCarta();
			std::cout << std::endl;
		}
		std::cout << "Ingrese el TipoCarta que desea jugar o (-1) si no desea jugar ninguna: " << std::endl;
		int numero;
		cin >> numero;

		if(numero >= 0 && numero < MAX_CARTAS) {
			switch(turnos->frente()->getCartas(numero).getTipoCarta()){
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
					irAtras(tablero, ultimosTableros);
					break;
				case PermutarLugar:
					std::cout <<"Juega carta PermutarLugar" << std::endl;
					permutarLugar(tablero);
					break;
				case TurnoDoble:
					std::cout <<"Juega carta TurnoDoble" << std::endl;
					turnoDoble(tablero, turnos, dim, cantJugadores);
					break;
			}
		} else {
			std::cout <<"No juega ninguna carta" << std::endl;
		}
		
		ultimosTableros->push(tablero->guardarEstado()); //agrega a la pila el ultimo tablero guardado
		turnos->acolar(turnos->desacolar());
	}

	tablero->destruir();
	ultimosTableros->pilaDestruir();
	turnos->ColaDestruir(); 
	return 0; 
}

