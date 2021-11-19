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
	//Jugador* siguiente;

public:
	/* PRE:
	 * POST
	 */
	Jugador();
	/* PRE:
	 * POST
	 */
	virtual ~Jugador();
	void setFicha(char ficha);
	/* PRE:
	 * POST
	 */
	char getFicha();
	/* PRE:
	 * POST	delete this;
	 */
	std::string getNombre();
	//Puntero
	Carta* getCartas(size_t pos);
	//Carta* getCartasPuntero();

};


#endif /* SRC_JUGADOR_H_ */
