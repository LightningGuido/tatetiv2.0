/*
 * Tateti.h
 *
 *  Created on: 18 nov. 2021
 *      Author: catalina
 */

#ifndef SRC_TATETI_H_
#define SRC_TATETI_H_

#include "jugador.h"
#include "tablero.h"
#include "cola.h"
#include "pila.h"
#include <string>
#include <fstream>


class Tateti {
private:
	Tablero* tablero;
	Cola* turnos; //orden de jugadores
	Pila* historialTableros;
	//Jugador* jugadorActual;
	Jugador* jugadorGanador; //se inicializa como NULL
	Jugador** jugadores;
public:
	Tateti();
	void inicializarTateti();
	virtual ~Tateti();
	bool anchuraValida(size_t f);
	bool alturaValida(size_t c);
	bool profundidadValida(size_t c);
	bool sonValoresIguales(Casillero* casillaUno, Casillero* casillaDos);
	bool sonFichasIguales(char fichaUno, char fichaDos);
	bool posicionValida (int ancho, int altura, int profundidad);
	//bool hayFicha (size_t ancho, size_t altura, size_t profundidad);
	int obtenerAncho ();
	int obtenerAltura ();
	int obtenerProfundidad ();
	void colocarFicha (Jugador* actual);
	bool movimientoValido(int x1, int y1, int z1, int x2, int y2, int z2);
	void moverFicha(Jugador* actual);
	void fichasIniciales(Jugador* actual);
	void turno(Jugador* actual);
	void ejecutar();
	void bloquearFicha();
	void bloquearCasillero();
	void perderTurno();
	void irAtras();
	bool permutarLugar();
	void turnoDoble();
	bool esNumero(std::string a);

};

#endif /* SRC_TATETI_H_ */
