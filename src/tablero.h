/*
 * tablero.h
 *
 *  Created on: Nov 9, 2021
 *      Author: guido
 */

#ifndef SRC_TABLERO_H_
#define SRC_TABLERO_H_


#include "casillero.h"

class Tablero {
private:
	Casillero ***casillero;
	unsigned int cantidadFichas;
	size_t anchura;
	size_t altura;
	size_t profundidad;

public:
	void setAnchura(size_t ancho);
	void setAltura(size_t alto);
	void setProfundidad(size_t profundo);
	Tablero(size_t ancho, size_t alto, size_t profundo);

};


#endif /* SRC_TABLERO_H_ */
