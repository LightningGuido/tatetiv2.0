/*
 * main.cpp
 *
 *  Created on: Nov 9, 2021
 *      Author: guido
 */

/*#include "tablero.h"
#include "jugador.h"
#include "pila.h"
#include "cola.h"
#include "juego.h"*/
#include "Tateti.h"

using namespace std;


int main() {

	Tateti* miTateti = new Tateti;
	//falta una funcion que inicialice
	miTateti->ejecutar();
	delete miTateti;
	return 0;
}

/*
int main2 (void){

	Tateti* miTateti = new Tateti();

	miTateti->inicializar(); //inicializa el tateti
	miTateti->jugar();
	delete miTateti;


	return 0;
}
*/
