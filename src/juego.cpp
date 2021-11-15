/*
 * juego.cpp
 *
 *  Created on: Nov 11, 2021
 *      Author: guido
 */


#include "juego.h"
using namespace std;

bool anchuraValida(size_t f, Tablero *tablero){
	if(f > (-1) && f <= (tablero->getAnchura())){
		return true;
	}
	return false;
}

bool alturaValida(size_t c, Tablero *tablero){
	if(c > (-1) && c < (tablero->getAltura())){
		return true;
	}
	return false;
}

bool profundidadValida(size_t c, Tablero *tablero){
	if(c > (-1) && c < (tablero->getProfundidad())){
		return true;
	}
	return false;
}

bool posicionValida (Tablero *tablero, size_t ancho, size_t altura, size_t profundidad){

	if(tablero->casillero[ancho][altura][profundidad]->getValor() == VACIO){
			return true;
		}

	return false;
}

size_t obtenerAncho (Tablero *tablero){
	size_t a;
	cout << "Indique un valor de ancho: " << endl;
		cin >> a;

	if(anchuraValida(a, tablero)){
		return a;
	}
	else{
		cout << "Valor de ancho invalido. Intente de nuevo." << endl;
		return obtenerAncho(tablero);
	}
}

size_t obtenerAltura (Tablero *tablero){
	size_t c;
	cout << "Indique un valor de altura: " << endl;
		cin >> c;

	if(alturaValida(c, tablero)){
		return c;
	}

	else{
		cout << "Valor de altura invalido. Intente de nuevo." << endl;
		return obtenerAltura(tablero);
	}
}

size_t obtenerProfundidad (Tablero *tablero){
	size_t c;
	cout << "Indique un valor de profundidad: " << endl;
		cin >> c;

	if(profundidadValida(c, tablero)){
		return c;
	}

	else{
		cout << "Valor de altura invalido. Intente de nuevo." << endl;
		return obtenerProfundidad(tablero);
	}
}

void colocarFicha (Tablero *tablero, Jugador *jugador){
	cout << "JUGADOR " << jugador->getNombre() << endl;
	size_t ancho = obtenerAncho(tablero);
	size_t altura = obtenerAltura(tablero);
    size_t profundidad = obtenerProfundidad(tablero);

	if(posicionValida(tablero, ancho, altura, profundidad)){
		(tablero->casillero[ancho][altura][profundidad])->getValor() = (jugador->getFicha());
	}
	else{
		cout << "Casilla no valida. Intente de nuevo." << endl;
		colocarFicha(tablero, jugador);
	}
}

bool movimientoValido(Tablero *tablero, Jugador *jugador, size_t anchoUno, size_t alturaUno, size_t profundidadUno, size_t anchoDos, size_t alturaDos, size_t profundidadDos){
	if((tablero->casillero[anchoUno][alturaUno][profundidadUno])->getValor() != jugador->getFicha() || !posicionValida(tablero, anchoDos, alturaDos, profundidadDos)){
		return false;
	}

	//falta agregar que sean movimientos de a una posicion
	return true;
}

bool moverFicha(Tablero *tablero, Jugador *jugador){

	size_t anchoUno;
	size_t alturaUno;
    size_t profundidadUno;
	size_t anchoDos;
	size_t alturaDos;
    size_t profundidadDos;

	cout << "JUGADOR " << jugador->getNombre() << endl;
	cout << "FICHA QUE SE MUEVE: " << endl;

	anchoUno = obtenerAncho(tablero);
	alturaUno = obtenerAltura(tablero);
    profundidadUno = obtenerProfundidad(tablero);

	cout << "NUEVA POSICION: " << endl;

	anchoDos = obtenerAncho(tablero);
	alturaDos = obtenerAltura(tablero);
    profundidadDos = obtenerProfundidad(tablero);

	if(movimientoValido(tablero, jugador, anchoUno, alturaUno, profundidadUno, anchoDos, alturaDos, profundidadDos)){
		(tablero->casillero[anchoUno][alturaUno][profundidadUno])->setValor(VACIO);
		(tablero->casillero[anchoDos][alturaDos][profundidadDos])->setValor(jugador->getFicha());
		return true;
	}

	else{
		cout << "El movimiento fallo. Intente de nuevo." << endl;
		moverFicha(tablero, jugador);
	}

	return false;
}

