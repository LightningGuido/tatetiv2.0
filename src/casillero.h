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

class Casillero {
private:
	char valor;

public:
	void setValor(char valor);
	char getValor();
};



#endif /* SRC_CASILLERO_H_ */
