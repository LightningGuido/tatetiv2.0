/*
 * casillero.h
 *
 *  Created on: Nov 9, 2021
 *      Author: guido
 */

#ifndef SRC_CASILLERO_H_
#define SRC_CASILLERO_H_

#include <iostream>
#include <fstream>
#include <string>
#include "Constantes.h"

enum StatusCasillero {
	Bloqueado = -1,
	Libre = 0,
	Ocupado = 1,
	OcupadoBloqueado = 2
};

class Casillero {
private:
	char valor;
	StatusCasillero estado;

public:
	/* PRE:
	 * POST:
	 */
	//Casillero();
	/* PRE:
	 * POST
	 */
	void setValor(char valor);
	/* PRE:
	 * POST:
	 */
	void setEstado(StatusCasillero estado);
	/* PRE:
	 * POST
	 */
	char getValor();
	/* PRE:
	 * POST
	 */
	StatusCasillero getEstado();
	bool estaVacio();
	bool estaLibre();
};



#endif /* SRC_CASILLERO_H_ */
