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
	//Resetea el ultimo movimiento
	IrAtras = 3,
	//Cambia de lugar la con la ficha de otro jugador
	PermutarLugar = 4,
	//Se pueden hacer dos movimientos en un turno
	TurnoDoble = 5
};

enum EstadoCarta{
	Jugada = 0,
	Disponible = 1
};


class Carta {
private:
	TipoCarta carta;
	EstadoCarta estado;

public:
	/* PRE: -
	 * POST: crea una Carta lista para ser jugada con un TipoCarta aleatorio y un Estado Disponible
	 */
	Carta();
	/* PRE: -
	 * POST: Devuelve el TipoCarta de la Carta
	 */
	TipoCarta getTipoCarta();
	/* PRE: -
	* POST: Recibe un estado por parametro y lo setea como el Estado de la Carta
	*/
	void setEstado(EstadoCarta estado);
	/* PRE: -
	* POST: Devuelve el EstadoCarta de la Carta
	*/
	EstadoCarta getEstado();
	/* PRE: -
	* POST: Muestra por pantalla el TipoCarta de la Carta, si el EstadoCarta es Disponible
	*/
	void mostrarCarta();
	/* PRE: -
	* POST: Destruye la Carta
	*/
	virtual ~Carta();
};



#endif /* SRC_CARTAS_H_ */
