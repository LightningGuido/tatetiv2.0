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

	/* PRE:-
	 * POST: Crea un casillero con un valor VACIO y un StatusCasillero Disponible
	 */
	Casillero();
	/* PRE:-
	* POST: Recible un valor por parametro y lo setea como valor del Casillero
	*/
	void setValor(char valor);
	/* PRE:-
	 * POST:Recibe un estado por parametro y lo setea como StatusCasillero
	 */
	void setEstado(StatusCasillero estado);
	/* PRE:-
	 * POST: Devuelve el valor del Casillero
	 */
	char getValor();
	/* PRE:-
	 * POST: Devuelve el StatusCasillero del Casillero
	 */
	StatusCasillero getEstado();
	/* PRE:-
	* POST:Devulve true si el valor del casillero es VACIO y false en caso contrario
	*/
	bool estaVacio();
	/* PRE:-
	* POST:Devuelve true si el StatusCasillero es Libre y false en caso contrario
	*/
	bool estaLibre();
	/* PRE:-
	 * POST: Destruye el Casillero
	 */
	~Casillero();
};



#endif /* SRC_CASILLERO_H_ */
