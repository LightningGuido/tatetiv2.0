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

class Jugador {
private:
	std::string nombre;
	char ficha;
	unsigned int idTurno;
	Carta *cartas;

public:
	/* PRE:
	 * POST
	 */
	Jugador(unsigned int idTurno);
	/* PRE:
	 * POST
	 */
	void setFicha(char ficha);
	/* PRE:
	 * POST
	 */
	char getFicha();
	/* PRE:
	 * POST
	 */
	std::string getNombre();
	//Puntero
};


#endif /* SRC_JUGADOR_H_ */
