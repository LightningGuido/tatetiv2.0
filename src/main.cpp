/*
 * main.cpp
 *
 *  Created on: Nov 9, 2021
 *      Author: guido
 */

#include "Tateti.h"

using namespace std;


int main() {

	Tateti* miTateti = new Tateti;
	miTateti->inicializarTateti();
	miTateti->ejecutar();
	delete miTateti;
	return 0;
}

