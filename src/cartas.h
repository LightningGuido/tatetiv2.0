/*
 * cartas.h
 *
 *  Created on: Nov 9, 2021
 *      Author: guido
 */

#ifndef SRC_CARTAS_H_
#define SRC_CARTAS_H_

#include <iostream>
#include <string>

enum TipoCarta {
	//Saltea a quien sigue
	PerderTurno = 0,
	//La ficha bloqueada no se puede volver a mover
	BloquearFicha = 1,
	//El casillero bloqueado ya no juega
	BloquearCasillero = 2,
	//Resetea el movimiento del turno anterior
	IrAtras = 3,
	//Cambia de lugar la con la ficha de otro jugador
	PermutarLugar = 4,
	//Se pueden hacer dos movimientos en un turno
	TurnoDoble = 5
};


class Carta {
private:
	TipoCarta carta;

public:
	/* PRE:
	 * POST
	 */
	Carta();
	// 6 funciones para las cartas
	// llamada a las funciones
	/* PRE:
	 * POST
	 */
	TipoCarta getTipoCarta();
	void mostrarCarta();
	virtual ~Carta();
};



#endif /* SRC_CARTAS_H_ */
