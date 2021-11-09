/*
 * jugador.h
 *
 *  Created on: Nov 9, 2021
 *      Author: guido
 */

#ifndef SRC_JUGADOR_H_
#define SRC_JUGADOR_H_

#include <string>

class Jugador {
private:
	std::string nombre;
	char ficha;
	unsigned int idTurno;

private:
	Jugador(char ficha, std::string nombre, unsigned int idTurno);
	void setFicha(char ficha);
	char getFicha();
	std::string getNombre();
};


#endif /* SRC_JUGADOR_H_ */
