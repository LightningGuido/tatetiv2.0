/*
 * juego.cpp
 *
 *  Created on: Nov 11, 2021
 *      Author: guido
 */


#include "juego.h"
using namespace std;

bool anchuraValida(size_t f, Tablero *tablero){
	if(f >= 0 && f <= (tablero->getAnchura())){
		return true;
	}
	return false;
}

bool alturaValida(size_t c, Tablero *tablero){
	if(c >= 0 && c < (tablero->getAltura())){
		return true;
	}
	return false;
}

bool profundidadValida(size_t c, Tablero *tablero){
	if(c >= 0 && c < size_t(tablero->getProfundidad())){
		return true;
	}
	return false;
}

bool posicionValida (Tablero *tablero, size_t ancho, size_t altura, size_t profundidad){

	if(tablero->getCasillero(ancho, altura, profundidad).getValor() == VACIO && tablero->getCasillero(ancho, altura, profundidad).getEstado() == Libre){
			return true;
		}

	return false;
}

bool hayFicha (Tablero *tablero, Jugador* jugador, size_t ancho, size_t altura, size_t profundidad){

	if(tablero->getCasillero(ancho, altura, profundidad).getValor() == jugador->getFicha()){
			return true;
		}

	return false;
}

size_t obtenerAncho (Tablero *tablero){
	int a;
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
	int c;
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
	int c;
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
		tablero->getCasillero(ancho,altura,profundidad).setValor(jugador->getFicha());
		tablero->getCasillero(ancho,altura,profundidad).setEstado(Ocupado);
	}
	else{
		cout << "Casilla no valida. Intente de nuevo." << endl;
		colocarFicha(tablero, jugador);
	}
}

bool movimientoValido(Tablero *tablero, Jugador *jugador, size_t anchoUno, size_t alturaUno, size_t profundidadUno, size_t anchoDos, size_t alturaDos, size_t profundidadDos){
	if(tablero->getCasillero(anchoUno, alturaUno, profundidadUno).getValor() != jugador->getFicha() || !posicionValida(tablero, anchoDos, alturaDos, profundidadDos)){
		return false;
	}

	//falta agregar que sean movimientos de a una posicion
	return true;
}

void moverFicha(Tablero *tablero, Jugador *jugador){

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
		tablero->getCasillero(anchoUno, alturaUno, profundidadUno).setValor(VACIO);
		tablero->getCasillero(anchoUno, alturaUno, profundidadUno).setEstado(Libre);
		tablero->getCasillero(anchoDos, alturaDos, profundidadDos).setValor(jugador->getFicha());
		tablero->getCasillero(anchoDos, alturaDos, profundidadDos).setEstado(Ocupado);
		return;
	}

	else{
		cout << "El movimiento fallo. Intente de nuevo." << endl;
		moverFicha(tablero, jugador);
	}
}

void fichasIniciales(Jugador *jugador, Tablero *tablero){

	colocarFicha(tablero, jugador);
	//mostrarTablero(tablero);
	
}

void turno(Tablero *tablero, Jugador *jugador) {

	moverFicha(tablero, jugador);
	//mostrarTablero(tablero);
}

void bloquearFicha(Tablero *tablero) {

	size_t ancho;
	size_t altura;
    size_t profundidad;

    cout << "Ingrese la ficha a bloquear" << endl;

    ancho = obtenerAncho(tablero);
    altura = obtenerAltura(tablero);
    profundidad = obtenerProfundidad(tablero);

    if(tablero->getCasillero(ancho, altura, profundidad).getValor() == VACIO) {
    	cout << "No hay ficha en esa posicion" << endl;
    	bloquearFicha(tablero);
    }
    if(tablero->getCasillero(ancho, altura, profundidad).getEstado() == OcupadoBloqueado) {
    	cout << "La ficha ya esta bloqueada" << endl;
    	bloquearFicha(tablero);
    }
    tablero->getCasillero(ancho, altura, profundidad).setEstado(OcupadoBloqueado);
    return;
}

void bloquearCasillero(Tablero *tablero) {

	size_t ancho;
	size_t altura;
    size_t profundidad;

    cout << "Ingrese la ficha a bloquear" << endl;

    ancho = obtenerAncho(tablero);
    altura = obtenerAltura(tablero);
    profundidad = obtenerProfundidad(tablero);

    tablero->getCasillero(ancho, altura, profundidad).setValor(VACIO);
    tablero->getCasillero(ancho, altura, profundidad).setEstado(Bloqueado);

}

void perderTurno(Cola* jugadores){
	
	jugadores->acolar(jugadores->desacolar()); //desacolamos y acolamos al jugador siguiente

}

void irAtras(Tablero* tablero, Pila* tableros){

	tablero->setAltura(tableros->top()->getAltura());
	tablero->setAnchura(tableros->top()->getAnchura());
	tablero->setProfundidad(tableros->top()->getProfundidad());
	tablero->setCantidadFichas(tableros->top()->getCantidadFichas());


	for(size_t i = 0; i < tablero->getAnchura(); i++) {
		for(size_t j = 0; j < tablero->getAltura(); j++) {
			for(size_t k = 0; k < tablero->getProfundidad(); k++) {
				tablero->getCasillero(i, j, k).setValor(tableros->top()->getCasillero(i, j, k).getValor());
			}
		}
	}
}

bool permutarLugar(Tablero* tablero){

	size_t anchoUno;
	size_t alturaUno;
    size_t profundidadUno;
	size_t anchoDos;
	size_t alturaDos;
    size_t profundidadDos;
	
	cout << "Ingrese coordenadas de la primera ficha a permutar: " << endl;

	anchoUno = obtenerAncho(tablero);
	alturaUno = obtenerAltura(tablero);
    profundidadUno = obtenerProfundidad(tablero);

	if(tablero->getCasillero(anchoUno, alturaUno, profundidadUno).getValor() == VACIO){
		cout << "Coordenada de primer ficha invalida. Debe ser una casilla ocupada" << endl;
		return permutarLugar(tablero);
	}

	cout << "Ingrese coordenadas de la segunda ficha a permutar: " << endl;

	anchoDos = obtenerAncho(tablero);
	alturaDos = obtenerAltura(tablero);
    profundidadDos = obtenerProfundidad(tablero);

	if(tablero->getCasillero(anchoDos, alturaDos, profundidadDos).getValor() == VACIO){
		cout << "Coordenada de primer ficha invalida. Debe ser una casilla ocupada" << endl;
		return permutarLugar(tablero);
	}

	char fichaUno = tablero->getCasillero(anchoUno, alturaUno, profundidadUno).getValor();
	char fichaDos = tablero->getCasillero(anchoDos, alturaDos, profundidadDos).getValor();
	
	
	tablero->getCasillero(anchoUno, alturaUno, profundidadUno).setValor(fichaDos);
	tablero->getCasillero(anchoDos, alturaDos, profundidadDos).setValor(fichaUno);
	return true;
	
}

void turnoDoble(Cola* jugadores){

	jugadores->acolarFrente(jugadores->frente());

}










