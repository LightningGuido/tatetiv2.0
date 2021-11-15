/*
 * juego.h
 *
 *  Created on: Nov 11, 2021
 *      Author: guido
 */

#ifndef SRC_JUEGO_H_
#define SRC_JUEGO_H_


#include "jugador.h"
#include "tablero.h"
#include "cola.h"
#include "pila.h"

bool anchuraValida(size_t f, Tablero *tablero);
bool alturaValida(size_t c, Tablero *tablero);
bool profundidadValida(size_t c, Tablero *tablero);
bool posicionValida (Tablero *tablero, size_t ancho, size_t altura, size_t profundidad);
bool hayFicha (Tablero *tablero, Jugador* jugador, size_t ancho, size_t altura, size_t profundidad);
size_t obtenerAncho (Tablero *tablero);
size_t obtenerAltura (Tablero *tablero);
size_t obtenerProfundidad (Tablero *tablero);
void colocarFicha (Tablero *tablero, Jugador *jugador);
bool movimientoValido(Tablero *tablero, Jugador *jugador, size_t anchoUno, size_t alturaUno, size_t profundidadUno, size_t anchoDos, size_t alturaDos, size_t profundidadDos);
void moverFicha(Tablero *tablero, Jugador *jugador);
void fichasIniciales(Jugador *jugador, Tablero *tablero);
void turno(Tablero *tablero, Jugador *jugador);

#endif /* SRC_JUEGO_H_ */
