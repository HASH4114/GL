#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "Symbol.h"

class Etat;

class Automate{
public:
	Automate();
	virtual ~Automate();
private:
	void shift(Symbol s, Etat *e);
	//If we don't use a pointer, it has no choice but to be an object of the class
	//Etat, and Etat is abstract.
};

#endif
