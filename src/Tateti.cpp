/*
 * Tateti.cpp
 *
 *  Created on: 18 nov. 2021
 *      Author: catalina
 */

#include "Tateti.h"

Tateti::Tateti() {

	std::cout << "Bienvenido al TaTeTi v2.0" << std::endl;
	std::cout << "Ingrese la dimension 3D de su cubo" << std::endl;
	size_t dim;
		std::cin >> dim;
	Tablero *tablero = new Tablero(dim, dim ,dim);
	this->tablero = tablero;
	Pila* ultimosTableros = new Pila;
	this->historialTableros = ultimosTableros;
	ultimosTableros->push(tablero->guardarEstado()); //guardo el tablero en blanco por si se juega IrAtras en el primer turno
	tablero->imprimirMapaCoordenado();

		std::cout << "Ingrese la cantidad de jugadores" << std::endl;
		size_t cantJugadores;
		std::cin >> cantJugadores;


		Cola *turnos = new Cola();
		Nodo **nodos = new Nodo*[cantJugadores]();
		for (size_t i= 0; i< cantJugadores ;i++){
			nodos[i] = new Nodo;
		}

		Jugador **jugadores = new Jugador*[cantJugadores];

		for(size_t i = 0; i < cantJugadores; i++) {
			jugadores[i] = new Jugador();
			nodos[i]->setDato(jugadores[i]);
			turnos->acolar(nodos[i]);
		}
		this->turnos = turnos;
		this->jugadorGanador = NULL;

}

Tateti::~Tateti() {
	// TODO Auto-generated destructor stub
}

bool Tateti::anchuraValida(size_t f){

	if(f >= 0 && f < (this->tablero->getAnchura())){
		return true;
	}
	return false;

}

bool Tateti::alturaValida(size_t c){
	if(c >= 0 && c < (this->tablero->getAltura())){
		return true;
	}
	return false;
}

bool Tateti::profundidadValida(size_t c){
	if(c >= 0 && c < size_t(this->tablero->getProfundidad())){
		return true;
	}
	return false;
}

bool Tateti::sonValoresIguales(Casillero* casillaUno, Casillero* casillaDos){
	if(casillaUno->getValor() == casillaDos->getValor()){
		return true;
	} else{
		return false;
	}
}

bool sonFichasIguales(char fichaUno, char fichaDos){
	if(fichaUno == fichaDos){
		return true;
	} else{
		return false;
	}
}

bool Tateti::posicionValida (size_t ancho, size_t altura, size_t profundidad){

	if(this->tablero->getCasillero(ancho, altura, profundidad)->estaVacio() && this->tablero->getCasillero(ancho, altura, profundidad)->estaLibre()){
			return true;
		}

	return false;
}

size_t Tateti::obtenerAncho (){
	int a;
	std::cout << "Indique un valor de ancho: " << std::endl;
		std::cin >> a;

	if(anchuraValida(a)){
		return a;
	}
	else{
		std::cout << "Valor de ancho invalido. Intente de nuevo." << std::endl;
		return obtenerAncho();
	}
}

size_t Tateti::obtenerAltura (){
	int c;
	std::cout << "Indique un valor de altura: " << std::endl;
		std::cin >> c;

	if(alturaValida(c)){
		return c;
	}

	else{
		std::cout << "Valor de altura invalido. Intente de nuevo." << std::endl;
		return obtenerAltura();
	}
}

size_t Tateti::obtenerProfundidad (){
	int c;
	std::cout << "Indique un valor de profundidad: " << std::endl;
		std::cin >> c;

	if(profundidadValida(c)){
		return c;
	}

	else{
		std::cout << "Valor de profundidad invalido. Intente de nuevo." << std::endl;
		return obtenerProfundidad();
	}
}

void Tateti::colocarFicha (Jugador* actual){
	std::cout << "JUGADOR " << actual->getNombre() << std::endl;
	size_t x = this->obtenerAncho();
	size_t y = this->obtenerAltura();
    size_t z = this->obtenerProfundidad();

	if(this->posicionValida(x, y, z)){
		this->tablero->getCasillero(x, y, z)->setValor(actual->getFicha());
		this->tablero->getCasillero(x, y, z)->setEstado(Ocupado);
	}
	else{
		std::cout << "Casilla no valida. Intente de nuevo." << std::endl;
		this->colocarFicha(this->turnos->frente());
	}
}

bool Tateti::sonFichasIguales(char ficha1, char ficha2){
	if(ficha1 == ficha2){
		return true;
	}else{
		return false;
	}
}

bool Tateti::movimientoValido(size_t x1, size_t y1, size_t z1, size_t x2, size_t y2, size_t z2){
	if(!sonFichasIguales(this->tablero->getCasillero(x1, y1, z1)->getValor(), this->turnos->frente()->getFicha()) || !this->posicionValida(x2, y2, z2)){
		return false;
	}

	//falta agregar que sean movimientos de a una posicion
	return true;
}

void Tateti::moverFicha(Jugador* actual){

	size_t x1;
	size_t y1;
    size_t z1;
	size_t x2;
	size_t y2;
    size_t z2;

	std::cout << "JUGADOR " << actual->getNombre() << std::endl;
	std::cout << "FICHA QUE SE MUEVE: " << std::endl;

	x1 = this->obtenerAncho();
	y1 = this->obtenerAltura();
    z1 = this->obtenerProfundidad();

	std::cout << "NUEVA POSICION: " << std::endl;

	x2 = this->obtenerAncho();
	y2 = this->obtenerAltura();
    z2 = this->obtenerProfundidad();

	if(this->movimientoValido(x1, y1, z1, x2, y2, z2)){
		this->tablero->getCasillero(x1, y1, z1)->setValor(VACIO);
		this->tablero->getCasillero(x1, y1, z1)->setEstado(Libre);
		this->tablero->getCasillero(x2, y2, z2)->setValor(actual->getFicha());
		this->tablero->getCasillero(x2, y2, z2)->setEstado(Ocupado);
		return;
	}

	else{
		std::cout << "El movimiento fallo. Intente de nuevo." << std::endl;
		this->moverFicha(actual);
	}
}

void Tateti::fichasIniciales(Jugador* actual){

	this->colocarFicha(actual);

}

void Tateti::turno(Jugador* actual) {
	while(!this->tablero->hayGanador()){
			this->moverFicha(actual);
			//ademas de hacer correr los turnos
		//mostrarTablero(tablero);
	}
}

void Tateti::bloquearFicha() {

	size_t ancho;
	size_t altura;
    size_t profundidad;

    std::cout << "Ingrese la ficha a bloquear" << std::endl;

    ancho = this->obtenerAncho();
    altura = this->obtenerAltura();
    profundidad = this->obtenerProfundidad();

    if(this->tablero->getCasillero(ancho, altura, profundidad)->estaVacio()) {
    	std::cout << "No hay ficha en esa posicion" << std::endl;
    	this->bloquearFicha();
    }
    if(tablero->getCasillero(ancho, altura, profundidad)->getEstado() == OcupadoBloqueado) {
    	std::cout << "La ficha ya esta bloqueada" << std::endl;
    	this->bloquearFicha();
    }
    this->tablero->getCasillero(ancho, altura, profundidad)->setEstado(OcupadoBloqueado);
    return;
}

void Tateti::bloquearCasillero() {

	size_t ancho;
	size_t altura;
    size_t profundidad;

    std::cout << "Ingrese la ficha a bloquear" << std::endl;

    ancho = this->obtenerAncho();
    altura = this->obtenerAltura();
    profundidad = this->obtenerProfundidad();

    this->tablero->getCasillero(ancho, altura, profundidad)->setValor(VACIO);
    this->tablero->getCasillero(ancho, altura, profundidad)->setEstado(Bloqueado);

}

void Tateti::perderTurno(){
	this->turnos->acolar(this->turnos->desacolar()); //desacolamos y acolamos al jugador siguiente
}

void Tateti::irAtras(){
	//tiene problemas porque no setea como VACIO los casilleros que antes estaban ocupados

	this->tablero->setAltura(this->historialTableros->top()->getAltura());
	this->tablero->setAnchura(this->historialTableros->top()->getAnchura());
	this->tablero->setProfundidad(this->historialTableros->top()->getProfundidad());
	this->tablero->setCantidadFichas(this->historialTableros->top()->getCantidadFichas());


	for(size_t i = 0; i < this->tablero->getAnchura(); i++) {
		for(size_t j = 0; j < this->tablero->getAltura(); j++) {
			for(size_t k = 0; k < this->tablero->getProfundidad(); k++) {
				this->tablero->getCasillero(i, j, k)->setValor(this->historialTableros->top()->getCasillero(i, j, k)->getValor());
				this->tablero->getCasillero(i, j, k)->setEstado(this->historialTableros->top()->getCasillero(i, j ,k)->getEstado());
			}
		}
	}
}

bool Tateti::permutarLugar(){

	size_t x1;
	size_t y1;
    size_t z1;
	size_t x2;
	size_t y2;
    size_t z2;

	std::cout << "Ingrese coordenadas de la primera ficha a permutar: " << std::endl;

	x1 = this->obtenerAncho();
	y1 = this->obtenerAltura();
    z1 = this->obtenerProfundidad();

	if(this->tablero->getCasillero(x1, y1, z1)->estaVacio()){
		std::cout << "Coordenada de primer ficha invalida. Debe ser una casilla ocupada" << std::endl;
		return this->permutarLugar();
	}

	std::cout << "Ingrese coordenadas de la segunda ficha a permutar: " << std::endl;

	x2 = this->obtenerAncho();
	y2 = this->obtenerAltura();
    z2 = this->obtenerProfundidad();

	if(this->tablero->getCasillero(x2, y2, z2)->estaVacio()){
		std::cout << "Coordenada de primer ficha invalida. Debe ser una casilla ocupada" << std::endl;
		return this->permutarLugar();
	}

	char fichaUno = this->tablero->getCasillero(x1, y1, z1)->getValor();
	char fichaDos = this->tablero->getCasillero(x2, y2, z2)->getValor();


	this->tablero->getCasillero(x1, y1, z1)->setValor(fichaDos);
	this->tablero->getCasillero(x2, y2, z2)->setValor(fichaUno);
	return true;

}

void Tateti::turnoDoble(){

	size_t cantidadFichas = this->tablero->getCantidadFichas();
	size_t dimension = this->tablero->getAnchura() ;
	size_t cantidadJugadores = this->turnos->getTamanio();

	if( cantidadFichas < dimension * cantidadJugadores) {
		this->fichasIniciales(this->turnos->frente());
	} else {
		this->turno(this->turnos->frente());
	}
}


void Tateti::ejecutar(){
	size_t dim = this->tablero->getAnchura();
	size_t cantidadJugadores = this->turnos->getTamanio();

	for(size_t i = 0; i < cantidadJugadores; i++) {
		std::cout << this->turnos->frente()->getNombre() << std::endl;
		this->turnos->acolar(turnos->desacolar());
	}

	while(!this->tablero->hayGanador()) {
			//Colocan o mueven Fichas
		if(this->tablero->getCantidadFichas() < dim * cantidadJugadores) {
			this->fichasIniciales(this->turnos->frente());

		} else {
			this->turno(this->turnos->frente());
		}

	//Muestran y juegan cartas
		this->tablero->imprimirTablero();
		this->historialTableros->push(this->tablero->guardarEstado());
		for(size_t i = 0; i < MAX_CARTAS; i++){
			std::cout << i << ": ";
			this->turnos->frente()->getCartas(i)->mostrarCarta();
			std::cout << std::endl;
		}
		std::cout << "Ingrese el TipoCarta que desea jugar o (-1) si no desea jugar ninguna: " << std::endl;
		int numero;
		std::cin >> numero;

		if(numero >= 0 && numero < MAX_CARTAS) {
			switch(this->turnos->frente()->getCartas(numero)->getTipoCarta()){
				case PerderTurno:
					std::cout <<"Juega carta PerderTurno" << std::endl;
					this->perderTurno();
					break;
				case BloquearFicha:
					std::cout <<"Juega carta BloquearFicha" << std::endl;
					this->bloquearFicha();
					break;
				case BloquearCasillero:
					std::cout <<"Juega carta BloquearCasillero" << std::endl;
					this->bloquearCasillero();
					break;
				case IrAtras:
					std::cout <<"Juega carta IrAtras" << std::endl;
					this->irAtras();
					break;
				case PermutarLugar:
					std::cout <<"Juega carta PermutarLugar" << std::endl;
					this->permutarLugar();
					break;
				case TurnoDoble:
					std::cout <<"Juega carta TurnoDoble" << std::endl;
					this->turnoDoble();
					break;
			}
			} else {
				std::cout <<"No juega ninguna carta" << std::endl;
			}

			this->tablero->imprimirTablero();
			this->historialTableros->push(this->tablero->guardarEstado());
			this->turnos->acolar(this->turnos->desacolar());
		}

		//determinar ganardor
}



