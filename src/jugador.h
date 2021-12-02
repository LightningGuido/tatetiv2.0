/*
 * jugador.h
 *
 *  Created on: Nov 9, 2021
 *      Author: guido
 */

#ifndef SRC_JUGADOR_H_
#define SRC_JUGADOR_H_

#include <string>
#include "cartas.h"
#include "Constantes.h"

class Jugador {
private:
	std::string nombre;
	char ficha;
	Carta **cartas;

public:
	/* PRE:-
	 * POST: Crea un Jugador, su arreglo de cartas y, pidiendo al usuario por pantalla, le asigna un nombre y
	 * una ficha
	 */
	Jugador();
	/* PRE:-
	 * POST: Destruye al Jugador y libera la memoria que se habia alocado
	 */
	virtual ~Jugador();
	/* PRE:-
	* POST: Recibe una ficha por parametro y la setea como ficha del Jugador
	*/
	void setFicha(char ficha);
	/* PRE:-
	 * POST: Devuelve la ficha del Jugador
	 */
	char getFicha();
	/* PRE:-
	 * POST: Devuelve el nombre del Jugador
	 */
	std::string getNombre();
	/* PRE:-
	* POST: Devuelve la Carta que se encuentra en el arreglo de Cartas en la posicion que se pasa por parametro
	*/
	Carta* getCartas(int pos);

};


#endif /* SRC_JUGADOR_H_ */
