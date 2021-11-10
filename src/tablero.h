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
	size_t anchura;		//x
	size_t altura;		//y
	size_t profundidad;	//z

public:
	/* PRE:
	 * POST:
	 */
	Tablero(size_t ancho, size_t alto, size_t profundo);
	/* PRE:
	 * POST:
	 */
	void setAnchura(size_t ancho);
	/* PRE:
	 * POST:
	 */
	void setAltura(size_t alto);
	/* PRE:
	 * POST:
	 */
	void setProfundidad(size_t profundo);
	/* PRE:
	 * POST:
	 */
	void setCantidadFichas(size_t n);
	/* PRE:
	 * POST:
	 */
	unsigned int getCantidadFichas();
	/* PRE:
	 * POST:
	 */
	size_t getAnchura();
	/* PRE:
	 * POST:
	 */
	size_t getAltura();
	/* PRE:
	 * POST:
	 */
	size_t getProfundidad();
	/* PRE:
	 * POST:
	 */
	bool hayGanador();
	/* PRE:
	 * POST:
	 */
	bool ganadorPlanoAncho();
	/* PRE:
	 * POST:
	 */
	bool ganadorPlanoAnchoDiagonal1();
	/* PRE:
	 * POST:
	 */
	bool ganadorPlanoAnchoDiagonal2();
	/* PRE:
	 * POST:
	 */
	bool ganadorPlanoAlto();
	/* PRE:
	 * POST:
	 */
	bool ganadorPlanoAltoDiagonal1();
	/* PRE:
	 * POST:
	 */
	bool ganadorPlanoAltoDiagonal2();
	/* PRE:
	 * POST:
	 */
	bool ganadorPlanoProf();
	/* PRE:
	 * POST:
	 */
	bool ganadorPlanoProfDiagonal1();
	/* PRE:
	 * POST
	 */
	bool ganadorPlanoProfDiagonal2();
	/* PRE:
	 * POST:
	 */
	bool ganadorDiagonales3D();
};



#endif /* SRC_TABLERO_H_ */
