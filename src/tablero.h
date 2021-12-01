/*
 * tablero.h
 *
 *  Created on: Nov 9, 2021
 *      Author: guido
 */

#ifndef SRC_TABLERO_H_
#define SRC_TABLERO_H_


#include "casillero.h"
#include "Constantes.h"

class Tablero {
private:
	Casillero ****casillero;
	unsigned int cantidadFichas;
	size_t anchura;		//x
	size_t altura;		//y
	size_t profundidad;	//z

	/* PRE: -
	 * POST: Devuelve el valor logico true si hay un ganador que haya alineado vertical u horizontalmente sus fichas
	 * en algun valor de ancho del Tablero, y false en caso contrario
	 */
	bool ganadorPlanoAncho();
	/* PRE:-
	 * POST: Devuelve el valor logico true si hay un ganador que haya alineado diagonalmente (diagonal uno) sus fichas
	 * en algun valor de ancho del Tablero, y false en caso contrario
	 */
	bool ganadorPlanoAnchoDiagonal1();
	/* PRE:-
	 * POST:Devuelve el valor logico true si hay un ganador que haya alineado diagonalmente (diagonal dos) sus fichas
	 * en algun valor de ancho del Tablero, y false en caso contrario
	 */
	bool ganadorPlanoAnchoDiagonal2();
	/* PRE:-
	 * POST: Devuelve el valor logico true si hay un ganador que haya alineado vertical u horizontalmente sus fichas
	 * en algun valor de alto del Tablero, y false en caso contrario
	 */
	bool ganadorPlanoAlto();
	/* PRE: -
	 * POST:Devuelve el valor logico true si hay un ganador que haya alineado diagonalmente (diagonal 1) sus fichas
	 * en algun valor de alto del Tablero, y false en caso contrario
	 */
	bool ganadorPlanoAltoDiagonal1();
	/* PRE: -
	 * POST:Devuelve el valor logico true si hay un ganador que haya alineado diagonalmente (diagonal 2) sus fichas
	 * en algun valor de alto del Tablero, y false en caso contrario
	 */
	bool ganadorPlanoAltoDiagonal2();
	/* PRE: -
	 * POST:Devuelve el valor logico true si hay un ganador que haya alineado vertical u horizontalmente sus fichas
	 * en algun valor de profundidad del Tablero, y false en caso contrario
	 */
	bool ganadorPlanoProf();
	/* PRE: -
	 * POST: Devuelve el valor logico true si hay un ganador que haya alineado diagonalmente (diagonal 1) sus fichas
	 * en algun valor de profundidad del Tablero, y false en caso contrario
	 */
	bool ganadorPlanoProfDiagonal1();
	/* PRE: -
	 * POST: Devuelve el valor logico true si hay un ganador que haya alineado diagonalmente (diagonal 2) sus fichas
	 * en algun valor de profundidad del Tablero, y false en caso contrario
	 */
	bool ganadorPlanoProfDiagonal2();
	/* PRE: -
	 * POST: Devuelve el valor logico true si hay un ganador que haya alineado diagonalmente sus fichas
	 * a lo largo de la de profundidad del Tablero, y false en caso contrario
	 */
	bool ganadorDiagonales3D();
	/* PRE:-
	* POST:	Imprime por pantalla el Tablero recorriendo los distintos valores de ancho posibles, en su estado actual
	*/
	void imprimirAncho();
	/* PRE:-
	* POST:Imprime por pantalla el Tablero con las coordenadas para referendcia del usuario
	* recorriendo los distintos valores de ancho posibles
	*/
	void imprimirAnchoCoordenado();
	/* PRE:-
	* POST:Imprime por pantalla el Tablero recorriendo los distintos valores de alto posibles, en su estado actual
	*/
	void imprimirAlto();
	/* PRE:-
	* POST: Imprime por pantalla el Tablero con las coordenadas para referendcia del usuario
	* recorriendo los distintos valores de alto posibles
	*/
	void imprimirAltoCoordenado();
	/* PRE:-
	* POST:Imprime por pantalla el Tablero recorriendo los distintos valores de profundidad posibles, en su estado actual
	*/
	void imprimirProf();
	/* PRE: -
	* POST: Imprime por pantalla el Tablero con las coordenadas para referendcia del usuario
	* recorriendo los distintos valores de profundidad posibles
	*/
	void imprimirProfCoordenado();

public:
	/* PRE:-
	 * POST: Crea un Tablero con las dimensiones pasadas por parametro
	 */
	Tablero(size_t ancho, size_t alto, size_t profundo);
	/* PRE:-
	 * POST: Recibe un valor de ancho por parametro y lo setea como valor de ancho del Tablero
	 */
	void setAnchura(size_t ancho);
	/* PRE:-
	 * POST: Recibe un valor de altura por parametro y lo setea como valor de alto del Tablero
	 */
	void setAltura(size_t alto);
	/* PRE:-
	 * POST: Recibe un valor del profundidad por parametro y lo setea como valor de Profundidad del Tablero
	 */
	void setProfundidad(size_t profundo);
	/* PRE:-
	 * POST:Recibe un valor de cantidad de fichas por parametro y lo setea como valor de Cantidad de Fichas del Tablero
	 */
	void setCantidadFichas(size_t n);
	/* PRE:-
	 * POST: Devuelve la cantidad de Fichas del Tablero
	 */
	unsigned int getCantidadFichas();
	/* PRE:-
	 * POST: Devuelve el valor de anchura del Tablero
	 */
	size_t getAnchura();
	/* PRE:-
	 * POST: Devuelve el valor de altura del Tablero
	 */
	size_t getAltura();
	/* PRE:-
	 * POST: Devuelve el valor de profundidad del Tablero
	 */
	size_t getProfundidad();
	/* PRE:-
	 * POST: Devuelve el puntero al Casillero en las coordenadas pasadas por parametro
	 */
	Casillero* getCasillero(size_t x, size_t y, size_t z);
	/* PRE:-
	 * POST:Devuelve el valor logico true si hay un ganador del Juego o false en caso contrario
	 */
	bool hayGanador();
	/* PRE:-
	* POST:Crea y devuelve un nuevo Tablero que es una copia del Tablero
	*/
	Tablero* guardarEstado();
	/* PRE:-
	* POST: Imprime por pantalla el Tablero coordenado para la referencia del usuario
	*/
	void imprimirMapaCoordenado();
	/* PRE:-
	 * POST: Imprime por pantalla el Tablero en su estado Actual
	*/
	void imprimirTablero();
	/* PRE:-
	* POST: Destruye y libera la memoria alocada para el Tablero
	*/
	virtual ~Tablero();

};



#endif /* SRC_TABLERO_H_ */
