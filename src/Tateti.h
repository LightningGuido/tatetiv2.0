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

class Tateti {
private:
	Tablero* tablero;
	Cola* turnos;
	Pila* historialTableros;
	//Jugador* jugadorActual;
	Jugador* jugadorGanador;
public:
	Tateti();
	virtual ~Tateti();
	bool anchuraValida(size_t f);
	bool alturaValida(size_t c);
	bool profundidadValida(size_t c);
	bool sonValoresIguales(Casillero* casillaUno, Casillero* casillaDos);
	bool sonFichasIguales(char fichaUno, char fichaDos);
	bool posicionValida (size_t ancho, size_t altura, size_t profundidad);
	//bool hayFicha (size_t ancho, size_t altura, size_t profundidad);
	size_t obtenerAncho ();
	size_t obtenerAltura ();
	size_t obtenerProfundidad ();
	void colocarFicha (Jugador* actual);
	bool movimientoValido(size_t x1, size_t y1, size_t z1, size_t x2, size_t y2, size_t z2);
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

};

#endif /* SRC_TATETI_H_ */
