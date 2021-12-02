/*
 * Tateti.h
 *
 *  Created on: 18 nov. 2021
 *      Author: catalina
 */

#ifndef SRC_TATETI_H_
#define SRC_TATETI_H_

#include "jugador.h"
#include "tablero.h"
#include "cola.h"
#include "pila.h"
#include <string>
#include <fstream>


class Tateti {
private:
	Tablero* tablero;
	Cola* turnos;
	Pila* historialTableros;
	Jugador** jugadores;
public:
	/*PRE:-
	 * POST: Crea un Tablero con las refernencias a tablero, turnos, historialTableros, jugadorGanador y jugadores a NULL
	 */
	Tateti();
	/*PRE:-
	* POST: Da la bienvenida al usuario, pide a usuario las dimensiones del Tablero y la cantidad de jugadores.
	* Crea el Tablero con las dimensiones dadas y crea a los jugadores pedidos.
	*/
	void inicializarTateti();
	/*PRE:-
	* POST: Destruye y libera la memoria alocada para el Tateti
	*/
	virtual ~Tateti();
	/*PRE:-
	* POST:Recibe una anchura por paramentro y devuelve el valor logico true si es un valor de ancho
	* valido, y false en caso contrario
	*/
	bool anchuraValida(int f);
	/*PRE:-
	* POST: Recibe una altura por paramentro y devuelve el valor logico true si es un valor de alto
	* valido, y false en caso contrario
	*/
	bool alturaValida(int c);
	/*PRE: -
	* POST: Recibe una profundidad por paramentro y devuelve el valor logico true si es un valor de profundidad
	* valido, y false en caso contrario
	*/
	bool profundidadValida(int c);
	/*PRE: -
	* POST: Compara dos Casilleros pasados por parametro y devuelve el valor logico true si los valores de ambos
	* casillero son iguales, y false en caso contrario
	*/
	bool sonValoresIguales(Casillero* casillaUno, Casillero* casillaDos);
	/*PRE: -
	* POST: Compara dos Fichas pasadas por parametro y devuelve el valor logico true si los valores de ambas
	* fichas son iguales, y false en caso contrario
	*/
	bool sonFichasIguales(char fichaUno, char fichaDos);
	/*PRE: -
	* POST: Recibe tres coordenadas del Tablero y devuelve el valor logico true si la posicion indicada
	* puede ser ocupada, y false en caso contrario
	*/
	bool posicionValida (int ancho, int altura, int profundidad);
	/*PRE: -
	* POST: Pide al usuario un valor de ancho y lo devuelve
	*/
	int obtenerAncho ();
	/*PRE: -
	* POST: Pide al usuario un valor de alto y lo devuelve
	*/
	int obtenerAltura ();
	/*PRE: -
	* POST: Pide al usuario un valor de profundidad y lo devuelve
	*/
	int obtenerProfundidad ();
	/*PRE: -
	* POST: Recibe un jugador como parametro, le pregunta coordenadas del tablero y, si las coordenadas
	* son validas, coloca la ficha del Jugador en el tablero
	*/
	void colocarFicha (Jugador* actual);
	/*PRE: -
	* POST: Recibe por parametro dos coordenadas (una incial y otra final), y devuelve el valor logico true
	* si el movimiento de la ficha desde la coordenada inicial hasta la final es valido,
	* false en caso contrario
	*/
	bool movimientoValido(int x1, int y1, int z1, int x2, int y2, int z2);
	/*PRE:-
	* POST: Recibe un Jugador por parametro y, si el movimiento que pretende es valido,
	* realiza el movimiento de una ficha del tablero del Jugador desde un origen
	* hacia una nueva posicion
	*/
	void moverFicha(Jugador* actual);
	/*PRE:-
	* POST: Recibe un jugador por parametro y realiza la operacion de colocar una ficha en una posicion,
	* pedida al jugador, si esta es valida.
	*/
	void fichasIniciales(Jugador* actual);
	/*PRE: -
	* POST: Recibe un jugador por parametro y realiza un movimiento, si es valido, sobre el tablero
	* de una ficha del jugador pasado hacia otra coordenada del tablero
	*/
	void turno(Jugador* actual);
	/*PRE:-
	* POST: Pone en funcionamiento el juego, mientras no haya ningun jugador ganador,
	* coloca las fichas iniciales de cada jugador o realiza los movimientos correspondientes
	* en cada turno, muestra el estado actual del tablero y, si el jugador quiere jugar una carta, la pone en funcionamiento
	*/
	void ejecutar();
	/*PRE: El jugador, en su turno, jugo la carta BloquearFicha
	* POST: Le pide al juagdor que la jugo valores de coordenada de Tablero para bloquear la ficha que
	* se encuentre en esa posicion. La ficha no podra ser movida a lo largo de todo el juego
	*/
	void bloquearFicha();
	/*PRE: El jugador, en su turno, jugo la carta BloquearCasillero
	* POST: El casillero queda fuera de juego. Se setea el valor como vacio y su estado como
	* Bloqueado, no puede volver a utilizarse
	*/
	void bloquearCasillero();
	/*PRE: El jugador, en su turno, jugo la carta PerderTurno
	* POST: El jugador siguiente al que juega la carta se ve salteado del orden y pierde un turno, dejando que juegue
	* el siguiente a el.
	*/
	void perderTurno();
	/*PRE: El jugador, en su turno, jugo la carta IrAtras
	* POST: Deshace el ultimo movimiento realizado por el Jugador que jugo la carta, volviendo el estado
	* del Tablero un movimiento atràs en el juego
	*/
	void irAtras();
	/*PRE: El jugador, en su turno, jugo la carta PermutarLugar
	* POST: Permite intercambiar la posicion de dos fichas de jugadores cualesquiera en el tablero
	*/
	bool permutarLugar();
	/*PRE: El jugador, en su turno, jugo la carta TurnoDoble
	* POST: El jugador que jugo la carta luego de realizar su movimiento, vuelve a jugar nuevamente
	* como si su turno no hubiera ocurrido
	*/
	void turnoDoble();
	/*PRE: -
	* POST: Recibe una cadena por parametro y devuelve el valor logico true si la cadena se corresponde con
	*  un numero, y false en caso contrario
	*/
	bool esNumero(std::string a);

};

#endif /* SRC_TATETI_H_ */
