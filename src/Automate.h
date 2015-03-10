#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "Symbol.h"
#include <stack>

class Etat;
using namespace std; 

class Automate{
public:
	Automate();
	virtual ~Automate();
	void shift(Symbol s, Etat *e);
	//If we don't use a pointer, it has no choice but to be an object of the class
	//Etat, and Etat is abstract.
private:
	stack<Symbol> symbolStack;
	stack<Etat*> stateStack;
};

#endif
